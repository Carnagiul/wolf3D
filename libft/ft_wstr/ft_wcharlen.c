/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:12:06 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/29 23:39:39 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_unix_char_is_display_ii(int wc)
{
	if (wc >= 0x80 && wc <= 0x07FF)
		return (1);
	return (0);
}

int			ft_unix_char_is_display_iii(int wc)
{
	if (wc >= 0x0800 && wc <= 0xFFFF)
		return (1);
	return (0);
}

int			ft_unix_char_is_display_iv(int wc)
{
	if (wc >= 0x10000 && wc <= 0x10FFFF)
		return (1);
	return (0);
}

size_t		ft_wcharlen(int wc)
{
	if (wc <= 0x7F)
		return (1);
	else if (wc <= 0x7FF)
		return (2);
	else if (wc <= 0xFFFF)
		return (3);
	else if (wc <= 0x10FFFF)
		return (4);
	return (1);
}
