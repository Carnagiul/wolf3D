# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/18 01:20:25 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_math.a

SRC = $(shell find . -type f | grep "\.c")

OBJ = ./ft_math_abs.o \
	  ./ft_math_div.o \
	  ./ft_math_factorial.o \
	  ./ft_math_mod.o \
	  ./ft_math_sum.o \
	  ./ft_pow.o \
	  ./ft_pow_ll.o \
	  ./ft_power.o \

OBJ_2 = ./obj/ft_math_abs.o \
		./obj/ft_math_div.o \
		./obj/ft_math_factorial.o \
		./obj/ft_math_mod.o \
		./obj/ft_math_sum.o \
		./obj/ft_pow.o \
		./obj/ft_pow_ll.o \
		./obj/ft_power.o \

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
