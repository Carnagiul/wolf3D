# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/18 01:21:23 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_utils.a

SRC = $(shell find . -type f | grep "\.c")

OBJ = ./ft_atoi.o \
	  ./ft_atoi_base.o \
	  ./ft_itoa.o \
	  ./ft_itoa_base.o \
	  ./ft_tolower.o \
	  ./ft_toupper.o \

OBJ_2 = ./obj/ft_atoi.o \
		./obj/ft_atoi_base.o \
		./obj/ft_itoa.o \
		./obj/ft_itoa_base.o \
		./obj/ft_tolower.o \
		./obj/ft_toupper.o \

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

display:
	@echo $(SRC)

re: fclean all

.PHONY : all clean fclean re
