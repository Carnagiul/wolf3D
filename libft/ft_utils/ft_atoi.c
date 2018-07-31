/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:01:51 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:31:41 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int	i;
	int	is_neg;
	int	number;

	i = 0;
	is_neg = 1;
	number = 0;
	while (ft_char_iswhitespaces(str[i]) == 1)
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		is_neg = (str[i++] == '-') ? -1 : 1;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		number *= 10;
		number += (str[i] - '0');
		i++;
	}
	return (is_neg * number);
}
