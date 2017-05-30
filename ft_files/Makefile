# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/29 23:29:41 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_files.a

SRC = $(shell find . -type f | grep "\.c")

OBJ= $(SRC:.c=.o)

OBJ_2 = $(addprefix obj/, $(OBJ))

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
	@echo $(OBJ_2)

re: fclean all

.PHONY : all clean fclean re
