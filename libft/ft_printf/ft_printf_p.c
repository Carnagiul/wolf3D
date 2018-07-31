/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 08:14:49 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/21 01:00:02 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printf_p_space(char *dup, t_print *print)
{
	int before;
	int after;

	before = print->precision->before_display;
	after = print->precision->after_display;
	if (print->precision->dot_found >= 1)
	{
		if (print->precision->before == 1)
			print->writed += ft_printf("% -*.*s", before, after, dup);
		else
			print->writed += ft_printf("% *.*s", before, after, dup);
	}
	else
	{
		if (print->precision->before == 1)
			print->writed += ft_printf("% -*s", before, dup);
		else
			print->writed += ft_printf("% *s", before, dup);
	}
	free(dup);
}

static void		ft_printf_p_end(char *dup, t_print *print)
{
	int before;
	int after;

	before = print->precision->before_display;
	after = print->precision->after_display;
	if (print->precision->dot_found >= 1)
	{
		if (print->precision->before == 1)
			print->writed += ft_printf("%-*.*s", before, after, dup);
		else
			print->writed += ft_printf("%*.*s", before, after, dup);
	}
	else
	{
		if (print->precision->before == 1)
			print->writed += ft_printf("%-*s", before, dup);
		else
			print->writed += ft_printf("%*s", before, dup);
	}
	free(dup);
}

static void		ft_printf_p_end_o(char *dup, t_print *print)
{
	int before;
	int after;

	before = print->precision->before_display;
	after = print->precision->after_display;
	if (print->flags->space >= 1)
	{
		if (print->precision->dot_found >= 1)
			print->writed += ft_printf("%0-*.*s", before, after, dup);
		else
			print->writed += ft_printf("%0-*s", before, dup);
	}
	else
	{
		if (print->precision->dot_found >= 1)
			print->writed += ft_printf("%0 -*.*s", before, after, dup);
		else
			print->writed += ft_printf("%0 -*s", before, dup);
	}
	free(dup);
}

void			ft_printf_p2(t_print *print)
{
	if (print->precision->after_display <= 3 &&
			print->precision->dot_found == 1)
		print->writed += ft_printf("0x");
	else if (print->precision->first != '0')
	{
		if (print->flags->space >= 1)
			ft_printf_p_space(ft_strdup("0x0"), print);
		else
			ft_printf_p_end(ft_strdup("0x0"), print);
	}
	else
		ft_printf_p_end_o(ft_strdup("0x0"), print);
}

void			ft_printf_p(void *addr, t_print *print)
{
	size_t		size;
	t_itoa		*itoa;

	size = (size_t)addr;
	print->flags->dieze = 1;
	print->precision->is_signed = 0;
	print->flags->space = 0;
	if ((print->precision->after_display >= 1 && size == 0) || size > 0)
	{
		itoa = k_itoa_k(print, size, 0, 'x');
		print->writed += ft_printf("%s", itoa->ret);
		ft_free_itoa(itoa);
	}
	else
		ft_printf_p2(print);
}
