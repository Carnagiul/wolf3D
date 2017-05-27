/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:45:23 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 00:14:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_printf_string(t_print *print)
{
	char	*str;

	str = ft_strnew(1);
	if (print->precision->before_display == 0)
		print->writed += ft_printf("(null)");
	else
	{
		if (print->precision->first != '0')
			str = ft_strdup("(null)");
		while (print->precision->before_display-- > 0 &&
				print->precision->first == '0')
			str = ft_free_join2("0", str);
		print->writed += ft_printf("%s", str);
	}
	free(str);
}

void		ft_printf_str_s(t_print *print, va_list *vl)
{
	char	*str;

	str = va_arg(*vl, char *);
	if (!str)
	{
		ft_printf_string(print);
		return ;
	}
	if (print->precision->after_display > (int)ft_strlen(str))
	{
		print->precision->after_display = 0;
		print->precision->dot_found = 0;
	}
	if (print->precision->after_display < (int)ft_strlen(str) &&
			print->precision->dot_found)
	{
		ft_getmax_print(print, print->precision->after_display, 1);
		ft_putnstr(str, print->precision->after_display);
		print->writed += print->precision->after_display;
		ft_getmax_print(print, print->precision->after_display, 0);
	}
	else
		ft_printf_str_s2(print, str);
}

static void	ft_printf_str_ls_2(t_print *print, wchar_t *str2)
{
	ft_getmax_print(print, (print->precision->after_display -
		ft_howputnstr(str2, print->precision->after_display, print)), 1);
	ft_putwnstr(str2, print->precision->after_display, print);
	print->writed += print->precision->after_display -
	ft_howputnstr(str2, print->precision->after_display, print);
	ft_getmax_print(print, (print->precision->after_display -
		ft_howputnstr(str2, print->precision->after_display, print)), 0);
}

void		ft_printf_str_ls(t_print *print, va_list *vl)
{
	wchar_t	*str2;

	str2 = va_arg(*vl, wchar_t *);
	if (!str2)
	{
		ft_printf_string(print);
		return ;
	}
	if (print->precision->after_display >= (int)ft_wstrlen(str2))
	{
		print->precision->after_display = 0;
		print->precision->dot_found = 0;
	}
	if (print->precision->after_display < (int)ft_wstrlen(str2) &&
			print->precision->dot_found)
		ft_printf_str_ls_2(print, str2);
	else
	{
		ft_getmax_print(print, ft_wstrlen(str2), 1);
		ft_putwstr(str2, print);
		ft_getmax_print(print, ft_wstrlen(str2), 0);
	}
}
