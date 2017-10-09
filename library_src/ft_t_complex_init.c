/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_complex_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 01:15:10 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 17:32:42 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_complex	ft_t_complex_init(double reel, double i)
{
	t_complex	complexe;

	complexe.r = reel;
	complexe.i = i;
	return (complexe);
}
