# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/18 01:20:48 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_mlx.a

SRC = $(shell find . -type f | grep "\.c")

OBJ = ./ft_mlx_gen_img.o ./ft_mlx_gen_win.o ./ft_mlx_get_info.o ./ft_mlx_menu_color.o ./ft_mlx_sphere.o ./ft_mlx_create_color.o

OBJ_2 = ./obj/ft_mlx_gen_img.o ./obj/ft_mlx_gen_win.o ./obj/ft_mlx_get_info.o ./obj/ft_mlx_menu_color.o ./obj/ft_mlx_sphere.o ./obj/ft_mlx_create_color.o

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
