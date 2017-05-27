/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 08:29:08 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/22 01:12:49 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void					ft_printf_lluint(t_print *print, va_list *vl)
{
	unsigned long long	nbr;
	t_itoa				*itoa;

	nbr = va_arg(*vl, unsigned long long);
	print->precision->is_signed = 0;
	print->flags->space = 0;
	itoa = k_itoa_k(print, nbr, 0, 'u');
	print->writed += ft_printf("%s", itoa->ret);
	ft_free_itoa(itoa);
}

void					ft_printf_uint(t_print *print, va_list *vl)
{
	unsigned long long	nbr;
	t_itoa				*itoa;

	if (print->flags->l == 2)
		nbr = va_arg(*vl, unsigned long long);
	else if (print->flags->l == 1)
		nbr = va_arg(*vl, unsigned long long);
	else if (print->flags->h == 2)
		nbr = (unsigned char)va_arg(*vl, unsigned int);
	else if (print->flags->h == 1)
		nbr = (unsigned short int)va_arg(*vl, int);
	else if (print->flags->j == 1)
		nbr = va_arg(*vl, uintmax_t);
	else if (print->flags->z == 1)
		nbr = va_arg(*vl, size_t);
	else
		nbr = va_arg(*vl, unsigned int);
	print->precision->is_signed = 0;
	print->flags->space = 0;
	itoa = k_itoa_k(print, nbr, 0, 'u');
	print->writed += ft_printf("%s", itoa->ret);
	ft_free_itoa(itoa);
}
