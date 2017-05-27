/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 06:38:16 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/29 07:49:35 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_printf_str_s2(t_print *print, char *str)
{
	ft_getmax_print(print, ft_strlen(str), 1);
	ft_putstr(str);
	print->writed += ft_strlen(str);
	ft_getmax_print(print, ft_strlen(str), 0);
}

void		ft_printf_str(t_print *print, const char *format, va_list *vl)
{
	if (format[print->i] == 's')
	{
		if (print->flags->l != 1)
			ft_printf_str_s(print, vl);
		else
			ft_printf_str_ls(print, vl);
	}
	else if (format[print->i] == 'c')
	{
		if (print->flags->l == 1)
			ft_putwchar(va_arg(*vl, int), print);
		else
			ft_print_char(print, (char)va_arg(*vl, int));
	}
	else if (format[print->i] == 'S')
		ft_printf_str_ls(print, vl);
	else if (format[print->i] == 'C')
		ft_putwchar(va_arg(*vl, int), print);
}
