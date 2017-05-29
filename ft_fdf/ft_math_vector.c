/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 21:52:00 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/28 21:56:20 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector		create_vector(double x, double y)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = 0;
	return (v);
}

t_vector		create_vector3d(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}
