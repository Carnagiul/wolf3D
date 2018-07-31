/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 03:52:41 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 04:15:00 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_precision_first_start(t_print *print, char *ret)
{
	if (print->precision->before_display == 0)
	{
		if (print->precision->dot_found == 1 &&
			print->precision->after_display == 0 &&
			ft_strlen(ret) == 1)
		{
			free(ret);
			ret = ft_strdup("\0");
		}
	}
	else if (print->precision->before_display >= 1)
	{
		if (print->precision->dot_found == 1 &&
			print->precision->after_display == 0 &&
			ft_strlen(ret) == 1)
		{
			free(ret);
			ret = ft_strdup(" \0");
		}
	}
	return (ret);
}

char		*ft_precision_first(t_print *print, char *ret, char *d)
{
	ft_debeug_in_console("ft_precision_first start", print, ret, d);
	ret = ft_precision_first_start(print, ret);
	ft_debeug_in_console("ft_precision_first mid", print, ret, d);
	if (print->precision->after_display > 1)
		while ((int)(ft_strlen(ret) + ft_strlen(d)) <
				print->precision->after_display)
			ret = ft_free_join2("0\0", ret);
	ft_debeug_in_console("ft_precision_first end", print, ret, d);
	return (ret);
}
