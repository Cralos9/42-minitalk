# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 13:53:03 by cacarval          #+#    #+#              #
#    Updated: 2023/05/26 14:44:11 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
PRINTF_PATH = libft/libft.a
CFLAGS = -Wall -Wextra -Werror

all: 	
		${MAKE} libft
		cc ${CFLAGS} client.c ${PRINTF_PATH} -o client
		cc ${CFLAGS} server.c ${PRINTF_PATH} -o server

clean:
		${MAKE} libft clean

fclean: clean
		${MAKE} libft fclean
		rm -f server client

re: fclean all

.PHONY: all clean fclean re

.SILENT:
