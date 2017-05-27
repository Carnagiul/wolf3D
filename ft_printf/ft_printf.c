/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 05:22:52 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 03:39:29 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_getmax_print(t_print *print, int len, int first)
{
	int		i;

	i = print->precision->before_display;
	i *= (print->precision->before == 1) ? -1 : 1;
	if (i != 0)
	{
		if (first == 1 && i > 0)
			while (len++ < print->precision->before_display)
				print->writed += ft_printf("%c", print->precision->first);
		else if (first == 0 && i < 0)
			while (len++ < print->precision->before_display)
				print->writed += ft_printf("%c", print->precision->first);
	}
}

void		ft_printf_next(const char *format, t_print *print)
{
	if (format[print->i] == '@' && PRINTF_COLOR_ON == 1)
		ft_printf_color(print, format);
	else if (format[print->i] == '?' && PRINTF_HELP_ON == 1)
		ft_printf_help(print);
	else if (format[print->i] == '!' && PRINTF_DEBEUG_ON == 1)
		ft_printf_debeug(print);
	else
	{
		ft_putchar(format[print->i++]);
		print->writed++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	vl;
	t_print	*print;
	int		ret;

	print = ft_init_printf();
	va_start(vl, format);
	va_copy(print->va_cpy, vl);
	while (format[print->i])
	{
		if (format[print->i] == '%')
			ft_parser_percent(format, print, &vl);
		else
			ft_printf_next(format, print);
	}
	ret = print->writed;
	va_end(vl);
	ft_free_print(print);
	return (ret);
}
