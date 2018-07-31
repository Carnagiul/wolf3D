/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:19:24 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/19 00:20:00 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnstr(const char *str, int len)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	else
	{
		while (len > 0 && str[i])
		{
			len--;
			ft_putchar(str[i]);
			i++;
		}
	}
}
