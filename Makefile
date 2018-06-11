# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 13:48:43 by vlvereta          #+#    #+#              #
#    Updated: 2018/04/18 13:49:06 by vlvereta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = ft_ssl

OBJ = srcs/ft_ssl.o srcs/ssl_init_and_check.o srcs/ssl_process.o srcs/ssl_readfile.o \
	srcs/md5.o srcs/md5_rounds.o srcs/sha256.o srcs/sha512.o srcs/sha_256_512_output.o

FLAGS = -Wall -Wextra -Werror

LIBFT = make -C $(LIB_FOLDER)

LIB_FOLDER = ./libft/


all: $(NAME)

$(NAME): $(OBJ)
	@	$(LIBFT)
	@	$(CC) -o $(NAME) $(OBJ) -L$(LIB_FOLDER) -lft

%.o: %.c
	@	$(CC) -o $@ -c $< -Iincludes $(FLAGS)

clean:
	@	make -C $(LIB_FOLDER) clean
	@	rm -f $(OBJ)

fclean: clean
	@	make -C $(LIB_FOLDER) fclean
	@	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
