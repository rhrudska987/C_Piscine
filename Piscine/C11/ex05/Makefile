# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 14:57:16 by kyko              #+#    #+#              #
#    Updated: 2022/09/15 22:10:29 by kyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/do-op.c srcs/operator.c
NAME = do-op

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean :

fclean : clean
	rm -f $(NAME)

re : fclean all
