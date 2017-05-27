# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/18 01:19:56 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_list_lib.a

SRC = $(shell find . -type f | grep "\.c")

OBJ = ft_list_at.o \
	  ft_list_find.o \
	  ft_list_find_last.o \
	  ft_list_push_back.o \
	  ft_list_push_front.o \
	  ft_list_push_param.o \
	  ft_list_reverse.o \
	  ft_list_size.o \
	  ft_list_sort.o \
	  ft_lstadd.o \
	  ft_lstdel.o \
	  ft_lstdelone.o \
	  ft_lstiter.o \
	  ft_lstmap.o \
	  ft_lstnew.o \

OBJ_2 = obj/ft_list_at.o \
		obj/ft_list_find.o \
		obj/ft_list_find_last.o \
		obj/ft_list_push_back.o \
		obj/ft_list_push_front.o \
		obj/ft_list_push_param.o \
		obj/ft_list_reverse.o \
		obj/ft_list_size.o \
		obj/ft_list_sort.o \
		obj/ft_lstadd.o \
		obj/ft_lstdel.o \
		obj/ft_lstdelone.o \
		obj/ft_lstiter.o \
		obj/ft_lstmap.o \
		obj/ft_lstnew.o

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
	echo $(SRC)

re: fclean all

.PHONY : all clean fclean re
