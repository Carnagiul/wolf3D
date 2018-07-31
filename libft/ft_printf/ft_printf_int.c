/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 06:29:20 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/22 01:37:16 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_printf_int(t_print *print, va_list *vl)
{
	long long			hhh;
	int					test;
	unsigned long long	cc;
	t_itoa				*itoa;

	if (print->flags->h == 1)
		hhh = (short)va_arg(*vl, long long);
	else if (print->flags->h == 2)
		hhh = (char)va_arg(*vl, long long);
	else if (print->flags->l == 1)
		hhh = (long)va_arg(*vl, long long);
	else if (print->flags->l == 2)
		hhh = (long long)va_arg(*vl, long long);
	else if (print->flags->j == 1 || print->flags->z == 1)
		hhh = (long long)va_arg(*vl, long long);
	else
		hhh = (int)va_arg(*vl, long long);
	test = 0;
	if (hhh < 0)
		test = 1;
	cc = (hhh < 0) ? (hhh * -1) : hhh;
	itoa = k_itoa_k(print, cc, test, 'i');
	print->writed += ft_printf("%s", itoa->ret);
	ft_free_itoa(itoa);
}
