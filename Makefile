# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/10/09 21:30:15 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = ./main.c

OBJ = ./main.o

OBJ_2 = ./obj/main.o

INCLUDE = $(shell find . -type f | grep "\.h")

LIB = library_src/lib.a
LIB += ft_fdf/lib.a

CFLAGS = -g -lpthread -lmlx -framework OpenGL -framework AppKit mlx/libmlxS.a $(LIB)

all: $(NAME)

.PHONY : all clean fclean re lib

obj/%.o: %.c $(INCLUDE)
	gcc -o $@ -c $<  -Wall -Wextra -Werror

lib: $(INCLUDE)
	@make -C library_src
	@make -C ft_fdf

$(NAME): lib $(OBJ_2)
	@mkdir -p obj/
	@gcc -c $(SRC) -Wall -Werror -Wextra
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) -Wall -Wextra -Werror
	@mv -f $(OBJ) obj/

clean:
	@make -C library_src clean
	@make -C ft_fdf clean
	@rm -rf $(OBJ_2)
fclean: clean
	@make -C library_src fclean
	@make -C ft_fdf fclean
	@rm -f $(NAME)

re: fclean all
	@make -C library_src re
	@make -C ft_fdf re

update:
	@git add -A
	@git commit -m "update"
	@git push

testaaa:
	@say -v thomas $(cat Makefile) &
	@say -v thomas $(cat main.c) &
	@say -v thomas $(cat Makefile) &
	@say -v thomas $(cat Makefile) &
	@say -v thomas $(cat Makefile) &
