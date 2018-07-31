/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 06:41:01 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 06:20:59 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_parser_percent_2(const char *format, t_print *print, va_list *vl)
{
	print->i++;
	while (ft_char_is_delimiteur(format[print->i]) == 0)
	{
		ft_parser_checker(format[print->i], print, format[print->i - 1]);
		if (format[print->i] == '*')
		{
			if (print->precision->dot_found == 0 && print->len_found == 0)
			{
				if (print->precision->before_display != 0)
					print->precision->before_display = 0;
				print->len = va_arg(*vl, int);
				print->len_found = 1;
			}
			else if (print->precision->dot_found == 1 &&
					print->precision->after_display == 0)
				print->width = va_arg(*vl, int);
		}
		print->i++;
	}
}

static void	ft_init(const char *format, t_print *print, va_list *vl)
{
	if (print->precision->limits == 1)
	{
		print->precision->after_display = 0;
		print->precision->dot_found = 0;
	}
	if (print->flags->dollard == 0)
		ft_delimite_parser(print, format, vl);
	else
		ft_printf_dollard(print, format);
	print->i++;
	free(print->precision);
	free(print->flags);
	print->flags = NULL;
	print->precision = NULL;
	print->precision = ft_init_precision();
	print->flags = ft_init_flags();
}

void		ft_parser_percent(const char *format, t_print *print, va_list *vl)
{
	ft_parser_percent_2(format, print, vl);
	if (ft_char_is_delimiteur(format[print->i]) == -1)
	{
		if (format[print->i])
			ft_print_char(print, format[print->i++]);
		return ;
	}
	if (print->len_found == 1 && print->precision->before_display == 0)
		print->precision->before_display = ft_math_abs(print->len);
	if (print->len_found == 1 && print->len < 0)
		print->precision->before = 1;
	if (print->precision->first == '0' && print->precision->before == 0 &&
			print->flags->dieze > 1)
		print->precision->first = ' ';
	if (print->width != 0 && print->precision->dot_found == 1 &&
			print->precision->after_display == 0)
	{
		print->precision->after_display = ft_math_abs(print->width);
		if (print->width < 0)
		{
			print->precision->after_display = 0;
			print->precision->dot_found = 0;
		}
	}
	ft_init(format, print, vl);
}
