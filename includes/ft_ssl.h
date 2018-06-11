/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/06/02 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "md5.h"
# include "sha256.h"
# include "sha512.h"
# include "../libft/includes/libft.h"

# define OK 2147483647
# define ERROR -2147483648

typedef char		*(t_func)(char *, size_t);

typedef struct		s_com
{
	char			*group;
	char			*name;
	t_func			*func;
	char			*digest;
	char			p;
	char			quiet;
	char			reverse;
	char			isfile;
	char			wasout;
	struct s_com	*next;
}					t_com;

void				commands_init(t_com **com_list);
void				add_new_command(t_com **l, char *g, char *n, t_func f);
void				read_command_from_stdin(t_com *com_list);
t_com				*check_command(char *command, t_com *list);
void				stdin_operate(t_com *com);
void				collect_strings(char **s1, char *buff);
void				ssl_process(t_com *com, int ac, char **av);
int					check_flags(t_com *com, char *str);
int					string_operate(t_com *com, char	*message);
void				files_operate(t_com *com, int ac, char **av);
int					ssl_readfile(char *av, char **result);
void				format_output(t_com *com, char *name);
void				print_command_usage(t_com *com, char op);
void				print_invalid_command(char *command, t_com *list);
void				final_check(t_com *com);
void				clean_list(t_com **list);

#endif
