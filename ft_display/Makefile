# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/18 01:19:17 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_display.a

SRC = $(shell find . -type f | grep "\.c")

OBJ = ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putnstr.o ft_putstr.o ft_putstr_fd.o

OBJ_2 = obj/ft_putchar.o \
		obj/ft_putchar_fd.o \
		obj/ft_putendl.o \
		obj/ft_putendl_fd.o \
		obj/ft_putnbr.o \
		obj/ft_putnbr_fd.o \
		obj/ft_putnstr.o \
		obj/ft_putstr.o \
		obj/ft_putstr_fd.o

INCLUDE = $(shell find ../ -type f | grep "\.h")

obj/%.o: %.c
	mkdir -p obj/
	gcc -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ_2)
	gcc -c -Wall -Werror -Wextra $(SRC) -I ../
	ar rc $(NAME) $(OBJ)
	mv $(OBJ) obj/
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ_2)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
