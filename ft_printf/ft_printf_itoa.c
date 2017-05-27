/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 06:42:48 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 04:47:45 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned long long		ft_printf_itoa_next(t_print *print,
		long long hhh, va_list *vl)
{
	unsigned long long cc;

	cc = 0;
	if (print->flags->h == 1)
		cc = (unsigned short)va_arg(*vl, intmax_t);
	else if (print->flags->h == 2)
		cc = (unsigned char)va_arg(*vl, intmax_t);
	else if (print->flags->l == 2)
		cc = (unsigned long long)va_arg(*vl, intmax_t);
	else if (print->flags->z == 1)
		cc = (unsigned long long)va_arg(*vl, intmax_t);
	else if (print->flags->l == 1)
		cc = (unsigned long)va_arg(*vl, intmax_t);
	else if (print->flags->j == 1)
		cc = (unsigned long long)va_arg(*vl, intmax_t);
	else
		cc = (unsigned int)va_arg(*vl, intmax_t);
	return ((cc == 0) ? hhh : cc);
}

void							ft_printf_itoa(t_print *print,
		const char *format, va_list *vl)
{
	unsigned long long			hhh;
	t_itoa						*itoa;

	if (format[print->i] == 'O' ||
			(FT_PRINTF_MAJB == 1 && format[print->i] == 'B'))
	{
		print->flags->l = 1;
		print->flags->h = 0;
		print->flags->j = 0;
		print->flags->z = 0;
	}
	hhh = ft_printf_itoa_next(print, 0, vl);
	itoa = k_itoa_k(print, hhh, 0, format[print->i]);
	print->writed += ft_printf("%s", itoa->ret);
	ft_free_itoa(itoa);
}
