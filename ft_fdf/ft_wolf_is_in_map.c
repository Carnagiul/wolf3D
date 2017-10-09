/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_is_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:23:16 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 20:29:13 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			calc_if_ray_is_in_map(t_ray ray, t_coucou *coucou)
{
	if (ray.map.x >= coucou->map.height || ray.map.y >= coucou->map.width
			|| ray.map.x < 0 || ray.map.y < 0)
		return (1);
	return (0);
}
