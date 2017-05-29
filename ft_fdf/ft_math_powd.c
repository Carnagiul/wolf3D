/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_powd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 22:00:08 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/28 22:00:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_dpower(double n, size_t power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (n);
	return (n * ft_dpower(n, power - 1));
}

