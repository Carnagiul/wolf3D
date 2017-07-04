/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:18:12 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/03 19:37:25 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_ray	set_ray_side(t_ray ray)
{
	ray.step.x = (ray.raydir.x < 0) ? -1 : 1;
	if (ray.step.x == -1)
		ray.sidedist.x = (ray.raypos.x - ray.map.x) * ray.deltadist.x;
	else
		ray.sidedist.x = (ray.map.x + 1.0 - ray.raypos.x) * ray.deltadist.x;
	ray.step.y = (ray.raydir.y < 0) ? -1 : 1;
	if (ray.step.y == -1)
		ray.sidedist.y = (ray.raypos.y - ray.map.y) * ray.deltadist.y;
	else
		ray.sidedist.y = (ray.map.y + 1.0 - ray.raypos.y) * ray.deltadist.y;
	return (ray);
}

t_ray	init_ray(t_coucou *coucou, int x)
{
	t_ray	ray;

	ray.pos = create_vector(coucou->pos.x, coucou->pos.y);
	ray.dir = create_vector(coucou->dir.x, coucou->dir.y);
	ray.plan = create_vector(coucou->plan.x, coucou->plan.y);
	ray.camera = 2 * x / (double)coucou->win->width - 1;
	ray.raypos = create_vector(ray.pos.x, ray.pos.y);
	ray.raydir = create_vector(ray.dir.x + ray.plan.x *
			ray.camera, ray.dir.y + ray.plan.y * ray.camera);
	ray.map.x = (int)ray.raypos.x;
	ray.map.y = (int)ray.raypos.y;
	ray.deltadist.x = sqrt(1 + (ft_dpower(ray.raydir.y, 2) /
				ft_dpower(ray.raydir.x, 2)));
	ray.deltadist.y = sqrt(1 + (ft_dpower(ray.raydir.x, 2) /
				ft_dpower(ray.raydir.y, 2)));
	ray = set_ray_side(ray);
	ray.hit = 0;
	ray.side = 0;
	return (ray);
}
