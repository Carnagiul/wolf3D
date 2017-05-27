# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/05/18 01:21:00 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a

SRC = $(shell find . -type f | grep "\.c")

OBJ = ./ft_display.o \
	  ./ft_display_next.o \
	  ./ft_free_itoa.o \
	  ./ft_init_structs.o \
	  ./ft_itoa_base_struct.o \
	  ./ft_itoa_base_struct_next.o \
	  ./ft_parser_checker.o \
	  ./ft_print_display.o \
	  ./ft_printf.o \
	  ./ft_printf_color.o \
	  ./ft_printf_debeug.o \
	  ./ft_printf_dollard.o \
	  ./ft_printf_double.o \
	  ./ft_printf_help.o \
	  ./ft_printf_int.o \
	  ./ft_printf_itoa.o \
	  ./ft_printf_n.o \
	  ./ft_printf_p.o \
	  ./ft_printf_parser.o \
	  ./ft_printf_percent.o \
	  ./ft_printf_str.o \
	  ./ft_printf_string.o \
	  ./ft_printf_uint.o \

OBJ_2 = ./obj/ft_display.o \
		./obj/ft_display_next.o \
		./obj/ft_free_itoa.o \
		./obj/ft_init_structs.o \
		./obj/ft_itoa_base_struct.o \
		./obj/ft_itoa_base_struct_next.o \
		./obj/ft_parser_checker.o \
		./obj/ft_print_display.o \
		./obj/ft_printf.o \
		./obj/ft_printf_color.o \
		./obj/ft_printf_debeug.o \
		./obj/ft_printf_dollard.o \
		./obj/ft_printf_double.o \
		./obj/ft_printf_help.o \
		./obj/ft_printf_int.o \
		./obj/ft_printf_itoa.o \
		./obj/ft_printf_n.o \
		./obj/ft_printf_p.o \
		./obj/ft_printf_parser.o \
		./obj/ft_printf_percent.o \
		./obj/ft_printf_str.o \
		./obj/ft_printf_string.o \
		./obj/ft_printf_uint.o \

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
