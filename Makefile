# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    # +:+ +:+         +:+      #
#    By: tderive </var/spool/mail/tderive>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/05 15:40:35 by tderive           #+#    #+#              #
#    Updated: 2026/11/06 09:39:49 by tderive          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 		get_next_line
CC  =		gcc 
SRC =		get_next_line.c\
		get_next_line_utils.c\
		main.c
FLAG=		-Wall -Wextra -Werror

all: 
	$(CC) $(FLAG) -g3 -D BUFFER_SIZE=42 $(SRC) -o $(NAME)

clean:
	rm -f a.out

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
