# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 22:35:23 by mpark-ki          #+#    #+#              #
#    Updated: 2019/11/22 12:54:48 by mpark-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=32
FILES = get_next_line_utils.c get_next_line.c

.PHONY: all
all:
	gcc $(FLAGS) -o $(NAME) $(FILES)

.PHONY: clean
clean:
	/bin/rm -f *.o

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
