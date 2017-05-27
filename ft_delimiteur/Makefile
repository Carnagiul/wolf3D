# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/19 01:34:39 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_delimiteur.a

SRC = $(shell find . -type f | grep "\.c")
OBJ = ft_char_isalpha_maj.o ft_char_isalpha_min.o ft_char_iswhitespaces.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o
OBJ_2 = 	obj/ft_char_isalpha_maj.o \
			obj/ft_char_isalpha_min.o \
			obj/ft_char_iswhitespaces.o \
			obj/ft_isalnum.o \
			obj/ft_isalpha.o \
			obj/ft_isascii.o \
			obj/ft_isdigit.o \
			obj/ft_isprint.o \

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
