# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/07/04 23:04:33 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = ./main.c

OBJ = ./main.o

OBJ_2 = ./obj/main.o

INCLUDE = $(shell find . -type f | grep "\.h")

LIB = ft_delimiteur/lib.a
LIB += ft_display/lib.a
LIB += ft_gnl/lib.a
LIB += ft_gnl/lib.a
LIB += ft_list/t_point/lib.a
LIB += ft_list/t_complex/lib.a
LIB += ft_math/lib.a
LIB += ft_memory/lib.a
LIB += ft_printf/lib.a
LIB += ft_string/lib.a
LIB += ft_utils/lib.a
LIB += ft_wstr/lib.a
LIB += ft_fdf/lib.a
LIB += ft_mlx/lib.a
LIB += ft_files/lib.a

CFLAGS = -lpthread -lmlx -framework OpenGL -framework AppKit mlx/libmlxS.a $(LIB)

$(NAME): libmaker project_maker

obj/%.o: %.c
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
	make -C ft_files
	make -C ft_fdf

project_maker:
	mkdir -p obj/
	gcc -c $(SRC) -Wall -Werror -Wextra
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	mv -f $(OBJ) obj/

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
	make -C ft_files clean
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
	make -C ft_files fclean
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
	make -C ft_files re
	make -C ft_fdf re

update:
	git add -A
	git commit -m "update"
	git push

testaaa:
	$(LIBA)
.PHONY : all clean fclean re
