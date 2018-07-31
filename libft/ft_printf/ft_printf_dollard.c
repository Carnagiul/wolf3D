/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dollard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 01:45:46 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/21 02:04:20 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printf_dollard(t_print *print, const char *format)
{
	va_list	vl;
	int		i;

	va_copy(vl, print->va_cpy);
	i = 1;
	while (i < print->precision->before_display)
	{
		i++;
		va_arg(vl, void *);
	}
	print->precision->before_display = 0;
	print->precision->after_display = 0;
	print->precision->dot_found = 0;
	print->flags->dollard = 0;
	ft_delimite_parser(print, format, &vl);
	va_end(vl);
}
