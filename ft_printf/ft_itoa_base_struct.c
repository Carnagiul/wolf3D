/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 03:57:11 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 04:50:42 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void						ft_finish_itoa(t_itoa *itoa, char *ret, char *d,
		t_print *print)
{
	if (print->flags->dieze == 1)
	{
		d = ft_free_join2("0\0", d);
		if (itoa->base_len == 16)
		{
			if (itoa->is_maj == 1)
				d = ft_free_join1(d, "X\0");
			else
				d = ft_free_join1(d, "x\0");
			if (ft_strcmp(ret, "\0") == 0)
				d = ft_strdup("\0");
		}
		if (ft_strcmp(ret, "0\0") == 0)
			d = ft_strdup("\0");
	}
	ret = ft_precision_mid(print, ret, itoa, d);
	ft_debeug_in_console("ft_finish_itoa mid", print, ret, d);
	if (itoa->is_signed == 1 && itoa->base_len == 10 &&
			print->precision->first == '0')
		ret = ft_free_join2("-\0", ret);
	else if (itoa->is_signed == 0 && print->precision->is_signed == 1 &&
			itoa->base_len == 10 && print->precision->first == '0')
		ret = ft_free_join2("+\0", ret);
	ft_debeug_in_console("ft_finish_itoa end", print, ret, d);
	itoa->ret = ret;
}

static void						ft_mid_itoa(t_itoa *itoa, t_print *print,
		char *ret, char *d)
{
	ft_debeug_in_console("ft_mid_itoa start", print, ret, d);
	ret = ft_precision_first(print, ret, d);
	ft_debeug_in_console("ft_mid_itoa mid", print, ret, d);
	free(d);
	if (itoa->is_signed == 1 && itoa->base_len == 10 &&
			print->precision->first != '0')
		ret = ft_free_join2("-\0", ret);
	else if (itoa->is_signed == 0 && print->precision->is_signed == 1 &&
			itoa->base_len == 10 && print->precision->first != '0')
		ret = ft_free_join2("+\0", ret);
	ft_finish_itoa(itoa, ret, ft_strdup("\0"), print);
	ft_debeug_in_console("ft_mid_itoa end", print, ret, d);
}

static void						ft_itoa_k(t_itoa *itoa, t_print *print)
{
	char						*ret;
	int							i;
	char						*d;

	i = ft_pow_llu(itoa);
	ret = ft_strnew(ft_pow_llu(itoa) + 1);
	ret[i] = 0;
	i--;
	ft_gen_base(itoa);
	d = ft_strdup("\0");
	while (itoa->nbr >= (unsigned long long)itoa->base_len)
	{
		ret[i] = itoa->base[itoa->nbr % itoa->base_len];
		itoa->nbr /= itoa->base_len;
		i--;
	}
	ret[i] = itoa->base[itoa->nbr % itoa->base_len];
	if (print->flags->dieze == 1)
		if (itoa->base_len != 16)
			d = ft_strdup("0\0");
	ft_mid_itoa(itoa, print, ret, d);
}

t_itoa							*k_itoa_k(t_print *print,
		unsigned long long nbr, int is_signed, char c)
{
	t_itoa						*elem;
	int							base_len;

	base_len = 10;
	elem = (t_itoa *)malloc(sizeof(t_itoa));
	if (!elem)
		return (NULL);
	elem->nbr = nbr;
	elem->is_signed = is_signed;
	if (c == 'b')
		base_len = 2;
	if (c == 'o' || c == 'x' || c == 'X' || c == 'O')
	{
		base_len = (c == 'X' || c == 'x') ? 16 : 8;
		print->flags->space = 0;
		print->precision->is_signed = 0;
	}
	elem->base_len = base_len;
	elem->is_maj = (c == 'X') ? 1 : 0;
	ft_itoa_k(elem, print);
	return (elem);
}
