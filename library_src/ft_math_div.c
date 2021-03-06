/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:11:57 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:26:33 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_math_div(int a, int div)
{
	if (ft_math_mod(a, div) != 0)
		return ((a / div) - 1);
	return (a / div);
}
