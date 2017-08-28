# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/08/22 19:52:51 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a

VALUE = delimiteur

SRC = $(shell find . -type f | grep "\.c")

OBJ= $(SRC:.c=.o)

OBJ_2 = $(addprefix obj/, $(OBJ))

INCLUDE = $(shell find ../ -type f | grep "\.h")

obj/%.o: %.c $(INCLUDE)
	@mkdir -p obj/
	@gcc -o $@ -c $< $(CFLAGS)
	@echo "\033[1A\033[K\033[38;5;92mcompiling $@\033[0m"

$(NAME): $(OBJ_2)
	@gcc -c -Wall -Werror -Wextra $(SRC) -I ../
	@ar rc $(NAME) $(OBJ)
	@mv $(OBJ) obj/
	@ranlib $(NAME)
	@echo "\033[38;5;154mcompiling $(NAME) done\033[0m\n"

all: $(NAME)

clean:
	@rm -f $(OBJ_2)
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
