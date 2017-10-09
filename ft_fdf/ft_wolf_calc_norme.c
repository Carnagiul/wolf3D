/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_calc_norme.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:33:31 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 20:40:24 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_ray			calc_dist_from_hit(t_ray ray, t_coucou *coucou)
{
	if (ray.side == 0)
		ray.perpwalldist = (ray.map.x - ray.raypos.x + (1 - ray.step.x) / 2)
			/ ray.raydir.x;
	else if (ray.side == 2)
		ray.perpwalldist = 1000;
	else
		ray.perpwalldist = (ray.map.y - ray.raypos.y + (1 - ray.step.y) / 2) /
			ray.raydir.y;
	return (calc_two(ray, coucou));
}

t_color_mlx		ft_wolf_get_color_side(t_ray ray)
{
	t_color_mlx	color;

	if (ray.side == 0)
		color = (ray.raydir.x >= 0) ? create_color(0xFF, 0, 0) :
			create_color(0x00, 0xFF, 0);
	else if (ray.side == 2)
		color = create_color(0xFF, 0xFF, 0xFF);
	else
		color = (ray.raydir.y >= 0) ? create_color(0, 0, 0xFF) :
			create_color(0xFF, 0, 0xFF);
	return (color);
}
