/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 02:12:46 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/21 02:20:23 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printf_color(t_print *print, const char *format)
{
	print->i++;
	if (format[print->i] == 'R' || format[print->i] == 'r')
		ft_putstr(print->color->red);
	else if (format[print->i] == 'B' || format[print->i] == 'b')
		ft_putstr(print->color->blue);
	else if (format[print->i] == 'G' || format[print->i] == 'g')
		ft_putstr(print->color->green);
	else if (format[print->i] == 'Y' || format[print->i] == 'y')
		ft_putstr(print->color->yellow);
	else if (format[print->i] == 'C' || format[print->i] == 'c')
		ft_putstr(print->color->cyan);
	else if (format[print->i] == 'P' || format[print->i] == 'p')
		ft_putstr(print->color->purple);
	else if (format[print->i] == 'W' || format[print->i] == 'w')
		ft_putstr(print->color->white);
	else
		ft_putstr(print->color->eof);
	print->i++;
}
