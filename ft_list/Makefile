# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/08/22 19:56:12 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

$(NAME):
	@make -C libft
	@make -C t_point
	@make -C t_complex

all: $(NAME)

clean:
	@make -C libft clean
	@make -C t_point clean
	@make -C t_complex clean

fclean: clean
	@make -C libft fclean
	@make -C t_point fclean
	@make -C t_complex fclean

re: fclean all
	@make -C libft re
	@make -C t_point re
	@make -C t_complex re

.PHONY : all clean fclean re
