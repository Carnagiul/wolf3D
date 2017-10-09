/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 02:38:50 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 04:28:28 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printf_help(t_print *print)
{
	ft_putstr("\nAide de ft_printf : \n");
	ft_putstr("\nFlags basique@@ : h hh l ll j z\n");
	ft_putstr("\nFlags bonus@@ : L $ ' *\n");
	ft_putstr("\nFonction basique@@ : % s S c C d D i o O u U x X\n");
	ft_putstr("\nFonction Supplementaires : b f F e E g G a A\n");
	ft_putstr("\nFonction Supplementaires : @ ^ ? | !\n");
	print->i++;
}

void	ft_debeug_in_console(char *c, t_print *print, char *ret, char *d)
{
	static int in;

	if (in != 0 && in != 1)
		in = 0;
	if (PRINTF_CONSOLE_ON == 1 && in == 0)
	{
		in = 1;
		ft_printf("%s:\nret_len == %s%d%s\n", c, print->color->yellow,
				(int)ft_strlen(ret), print->color->eof);
		ft_printf("%s:\nd_len == %s%d%s\n", c, print->color->cyan,
				(int)ft_strlen(d), print->color->eof);
		in = 0;
	}
}
