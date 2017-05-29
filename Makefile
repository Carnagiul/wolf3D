# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/22 07:23:55 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = ./main.c
SRC2 = ./map_generator.c

OBJ = ./main.o
OBJ2 = ./map_generator.o

OBJ_2 = ./obj/main.o
OBJ_2 = ./obj/map_generator.o

INCLUDE = $(shell find . -type f | grep "\.h")

LIB = ft_delimiteur/libft_delimiteur.a
LIB += ft_display/libft_display.a
LIB += ft_gnl/libft_gnl.a
LIB += ft_gnl/libft_gnl.a
LIB += ft_list/t_point/libft_list_point.a
LIB += ft_list/t_complex/libft_list_complex.a
LIB += ft_math/libft_math.a
LIB += ft_memory/libft_memory.a
LIB += ft_printf/libft_printf.a
LIB += ft_string/libft_string.a
LIB += ft_utils/libft_utils.a
LIB += ft_wstr/libft_wstr.a
LIB += ft_fdf/libft_fdf.a
LIB += ft_mlx/libft_mlx.a

CFLAGS = -lpthread -lmlx -framework OpenGL -framework AppKit mlx/libmlxS.a $(LIB)

$(NAME):
	make libmaker
	make project_maker

obj/%.o: %.c
	mkdir -p obj/
	gcc -o $@ -c $< $(CFLAGS)

libmaker:
	make -C ft_delimiteur
	make -C ft_display
	make -C ft_gnl
	make -C ft_list
	make -C ft_math
	make -C ft_memory
	make -C ft_printf
	make -C ft_string
	make -C ft_utils
	make -C ft_wstr
	make -C ft_mlx
	make -C ft_fdf

project_maker:
	gcc -c $(SRC) -Wall -Werror -Wextra
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	mv -f $(OBJ) obj/
	gcc -c $(SRC2) -Wall -Werror -Wextra
	gcc -o generator $(OBJ2) $(CFLAGS)
	mv -f $(OBJ2) obj/

all: $(NAME)

clean:
	make -C ft_delimiteur clean
	make -C ft_display clean
	make -C ft_gnl clean
	make -C ft_list clean
	make -C ft_math clean
	make -C ft_memory clean
	make -C ft_printf clean
	make -C ft_string clean
	make -C ft_utils clean
	make -C ft_wstr clean
	make -C ft_mlx clean
	make -C ft_fdf clean
	rm -rf $(OBJ_2)
fclean: clean
	make -C ft_delimiteur fclean
	make -C ft_display fclean
	make -C ft_gnl fclean
	make -C ft_list fclean
	make -C ft_math fclean
	make -C ft_memory fclean
	make -C ft_printf fclean
	make -C ft_string fclean
	make -C ft_utils fclean
	make -C ft_wstr fclean
	make -C ft_mlx fclean
	make -C ft_fdf fclean
	rm -f $(NAME)

re: fclean all
	make -C ft_delimiteur re
	make -C ft_display re
	make -C ft_gnl re
	make -C ft_list re
	make -C ft_math re
	make -C ft_memory re
	make -C ft_printf re
	make -C ft_string re
	make -C ft_utils re
	make -C ft_wstr re
	make -C ft_mlx re
	make -C ft_fdf re

.PHONY : all clean fclean re
