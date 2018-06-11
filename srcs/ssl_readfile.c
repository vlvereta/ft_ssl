/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/06/11 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		ssl_readfile(char *av, char **result)
{
	int		fd;
	int		ret;
	char	buff[513];

	*result = NULL;
	ft_bzero(buff, 512);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	while ((ret = read(fd, buff, 512)))
	{
		if (ret == -1)
		{
			perror("Bad reading from file");
			if (*result)
				ft_memdel((void **)result);
			return (-1);
		}
		collect_strings(result, buff);
		ft_bzero(buff, 512);
	}
	close(fd);
	if (!(*result))
		return (0);
	return (1);
}

void	collect_strings(char **s1, char *buff)
{
	char	*result;

	if (*s1)
	{
		result = ft_strjoin(*s1, buff);
		ft_memdel((void **)s1);
		*s1 = result;
	}
	else
		*s1 = ft_strdup(buff);
}
