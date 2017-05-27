/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 04:42:58 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 05:24:12 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_printf_parser_digit_2(char c, char c2, t_print *print)
{
	if (ft_isdigit(c2) != 1 && c2 != '.')
		print->precision->limits = 1;
	else
	{
		print->precision->after_display *= 10;
		print->precision->after_display += c - '0';
	}
}

void		ft_printf_parser_digit(char c, ...)
{
	va_list	vl;
	t_print	*print;
	char	c2;

	va_start(vl, c);
	print = va_arg(vl, t_print *);
	c2 = (char)va_arg(vl, t_print *);
	va_end(vl);
	if (print->precision->before_display == 0 && c == '0' &&
			print->precision->dot_found == 0 && (c2 == '#' || c2 == '%' ||
				c2 == '+' || c2 == ' '))
	{
		print->precision->first = '0';
		return ;
	}
	if (print->precision->dot_found == 1)
		ft_printf_parser_digit_2(c, c2, print);
	else
	{
		print->precision->before_display *= 10;
		print->precision->before_display += c - '0';
	}
}

void		ft_printf_parser_flags(char c, ...)
{
	va_list	vl;
	t_print	*print;

	va_start(vl, c);
	print = va_arg(vl, t_print *);
	va_end(vl);
	if (c == 'h')
		print->flags->h++;
	if (c == 'l')
		print->flags->l++;
	if (c == 'j')
		print->flags->j++;
	if (c == 'z')
		print->flags->z++;
	if (c == '#')
		print->flags->dieze++;
	if (c == ' ')
		print->flags->space = 1;
	if (c == '$')
		print->flags->dollard++;
}

void		ft_printf_parser_specs(char c, ...)
{
	va_list	vl;
	t_print	*print;

	va_start(vl, c);
	print = va_arg(vl, t_print *);
	va_end(vl);
	if (c == '.')
		print->precision->dot_found = 1;
	if (c == '-' && print->precision->dot_found == 0)
		print->precision->before = 1;
	if (c == '+')
		print->precision->is_signed = 1;
}
