/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:32:58 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 04:29:57 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_precision_end(t_print *print, char *ret, t_itoa *itoa, char *d)
{
	ft_debeug_in_console("ft_precision_end start", print, ret, d);
	if (itoa != NULL)
	{
		if (itoa->base_len == 10 && (itoa->is_signed == 1 ||
				print->precision->is_signed == 1))
			print->precision->before_display--;
	}
	ft_debeug_in_console("ft_precision_end mid", print, ret, d);
	if (print->precision->before_display > print->precision->after_display &&
			print->precision->after_display != 0)
	{
		while ((int)(ft_strlen(ret) + ft_strlen(d)) <
				print->precision->before_display)
			d = ft_free_join1(d, " \0");
	}
	else
	{
		while ((int)(ft_strlen(ret) + ft_strlen(d)) <
				print->precision->before_display)
			d = ft_free_join1(d, "0\0");
	}
	ft_debeug_in_console("ft_precision_end end", print, ret, d);
	return (d);
}

void		ft_mid(t_print *print, char **ret, char **d, t_itoa *itoa)
{
	if (print->precision->first != '0')
	{
		if (print->precision->is_signed == 1 && print->precision->first == '0')
			while ((int)((ft_strlen(*ret)) + ft_strlen(*d)) <
					print->precision->before_display)
				*ret = ft_free_join1(*ret, "0\0");
		else if (print->precision->before == 1)
			while ((int)((ft_strlen(*ret)) + ft_strlen(*d)) <
					print->precision->before_display)
				*ret = ft_free_join1(*ret, " \0");
		else
			while ((int)((ft_strlen(*ret) + ft_strlen(*d))) <
					print->precision->before_display)
				*d = ft_free_join2(" \0", *d);
	}
	else
	{
		if (print->precision->before == 1)
			while ((int)(ft_strlen(*ret) + ft_strlen(*d)) <
					print->precision->before_display)
				*ret = ft_free_join1(*ret, " \0");
		else
			*d = ft_precision_end(print, *ret, itoa, *d);
	}
}

char		*ft_precision_mid(t_print *print, char *ret, t_itoa *itoa, char *d)
{
	ft_debeug_in_console("ft_precision_mid_start", print, ret, d);
	if (print->flags->space == 1 && print->precision->before_display >= 1)
		print->precision->before_display--;
	ft_debeug_in_console("ft_precision_mid_start_1", print, ret, d);
	if (print->precision->before_display > (int)(ft_strlen(ret) + ft_strlen(d)))
		ft_mid(print, &ret, &d, itoa);
	ft_debeug_in_console("ft_precision_mid_start_2", print, ret, d);
	if (itoa)
	{
		if (print->flags->space == 1 && print->precision->is_signed != 1
				&& itoa->is_signed != 1)
			d = ft_free_join2(" \0", d);
	}
	else
	{
		if (print->flags->space == 1 && print->precision->is_signed != 1)
			d = ft_free_join2(" \0", d);
	}
	ft_debeug_in_console("ft_precision_mid_start_end", print, ret, d);
	return (ft_free_join(d, ret));
}
