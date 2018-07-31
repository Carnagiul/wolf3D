/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:29:23 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 03:39:53 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putwstr(const wchar_t *str, t_print *print)
{
	int		i;
	int		writed;

	writed = 0;
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		print->writed += (int)ft_wcharlen(str[i++]);
	}
}

void		ft_print_char(t_print *print, int c)
{
	ft_getmax_print(print, 1, 1);
	ft_putchar(c);
	print->writed += (int)ft_wcharlen(c);
	ft_getmax_print(print, 1, 0);
}

void		ft_putwchar(int wc, t_print *print)
{
	if ((wc > 55295 && wc < 57344) || wc > 0x10FFFF)
	{
		print->writed = -1;
		return ;
	}
	ft_putchar(wc);
	print->writed += (int)ft_wcharlen(wc);
}

int			ft_howputnstr(wchar_t *str, int len, t_print *print)
{
	int		i;
	int		diff;

	diff = 0;
	i = 0;
	print->writed = diff + print->writed;
	while (str[i] != 0)
	{
		len -= (int)ft_wcharlen(str[i]);
		if (len < 0)
		{
			len += (int)ft_wcharlen(str[i]);
			return (len);
		}
		i++;
	}
	return (0);
}

void		ft_putwnstr(wchar_t *str, int len, t_print *print)
{
	int		i;
	int		diff;

	diff = 0;
	i = 0;
	print->writed = diff + print->writed;
	while (str[i] != 0)
	{
		len -= (int)ft_wcharlen(str[i]);
		if (len >= 0)
			ft_putchar(str[i++]);
		else
			return ;
	}
	return ;
}
