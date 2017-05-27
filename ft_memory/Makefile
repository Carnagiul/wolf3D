# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/18 01:20:34 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_memory.a

SRC = $(shell find . -type f | grep "\.c")

OBJ = ./ft_bzero.o \
	  ./ft_memalloc.o \
	  ./ft_memccpy.o \
	  ./ft_memchr.o \
	  ./ft_memcmp.o \
	  ./ft_memcpy.o \
	  ./ft_memdel.o \
	  ./ft_memmove.o \
	  ./ft_memset.o \

OBJ_2 = ./obj/ft_bzero.o \
		./obj/ft_memalloc.o \
		./obj/ft_memccpy.o \
		./obj/ft_memchr.o \
		./obj/ft_memcmp.o \
		./obj/ft_memcpy.o \
		./obj/ft_memdel.o \
		./obj/ft_memmove.o \
		./obj/ft_memset.o \

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
