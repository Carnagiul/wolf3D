# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/18 01:21:13 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_string.a

SRC = $(shell find . -type f | grep "\.c")

OBJ = ./ft_reverse.o \
	  ./ft_strcat.o \
	  ./ft_strchr.o \
	  ./ft_strclr.o \
	  ./ft_strcmp.o \
	  ./ft_strcpy.o \
	  ./ft_strdel.o \
	  ./ft_strdup.o \
	  ./ft_strequ.o \
	  ./ft_string_capitalize.o \
	  ./ft_striter.o \
	  ./ft_striteri.o \
	  ./ft_strjoin.o \
	  ./ft_strlcat.o \
	  ./ft_strlen.o \
	  ./ft_strmap.o \
	  ./ft_strmapi.o \
	  ./ft_strncat.o \
	  ./ft_strncmp.o \
	  ./ft_strncpy.o \
	  ./ft_strnequ.o \
	  ./ft_strnew.o \
	  ./ft_strnstr.o \
	  ./ft_strrchr.o \
	  ./ft_strsplit.o \
	  ./ft_strstr.o \
	  ./ft_strsub.o \
	  ./ft_strtrim.o \

OBJ_2 = ./obj/ft_reverse.o \
		./obj/ft_strcat.o \
		./obj/ft_strchr.o \
		./obj/ft_strclr.o \
		./obj/ft_strcmp.o \
		./obj/ft_strcpy.o \
		./obj/ft_strdel.o \
		./obj/ft_strdup.o \
		./obj/ft_strequ.o \
		./obj/ft_string_capitalize.o \
		./obj/ft_striter.o \
		./obj/ft_striteri.o \
		./obj/ft_strjoin.o \
		./obj/ft_strlcat.o \
		./obj/ft_strlen.o \
		./obj/ft_strmap.o \
		./obj/ft_strmapi.o \
		./obj/ft_strncat.o \
		./obj/ft_strncmp.o \
		./obj/ft_strncpy.o \
		./obj/ft_strnequ.o \
		./obj/ft_strnew.o \
		./obj/ft_strnstr.o \
		./obj/ft_strrchr.o \
		./obj/ft_strsplit.o \
		./obj/ft_strstr.o \
		./obj/ft_strsub.o \
		./obj/ft_strtrim.o \

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
