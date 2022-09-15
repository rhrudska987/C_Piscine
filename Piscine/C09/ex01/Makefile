# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 14:57:16 by kyko              #+#    #+#              #
#    Updated: 2022/09/13 01:56:49 by kyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes
TARGET = libft.a
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

all : $(TARGET)

ft_putchar : srcs/ft_putchar.c
	$(CC) $(CFLAGS) -c -o srcs/ft_putchar.o srcs/ft_putchar.c

ft_swap : srcs/ft_swap.c
	$(CC) $(CFLAGS) -c -o srcs/ft_swap.o srcs/ft_swap.c

ft_putstr : srcs/ft_putstr.c
	$(CC) $(CFLAGS) -c -o srcs/ft_putstr.o srcs/ft_putstr.c

ft_strlen : srcs/ft_strlen.c
	$(CC) $(CFLAGS) -c -o srcs/ft_strlen.o srcs/ft_strlen.c

ft_strcmp : srcs/ft_strcmp.c
	$(CC) $(CFLAGS) -c -o srcs/ft_strcmp.o srcs/ft_strcmp.c


$(TARGET) : $(ft_putchar) $(ft_swap) $(ft_putstr) $(ft_strlen) $(ft_strcmp) $(OBJS)
	ar -rc $(TARGET) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
