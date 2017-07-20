/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 07:45:07 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/20 09:12:22 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_ray	ft_wolf_calc_hit_entity2(t_ray ray, t_entity *ent, t_coucou *coucou)
{
	ray.lineheight = (int)(coucou->win->height / ray.perpwalldist);
	ray.start = -ray.lineheight / 2 + coucou->win->height / 2;
	ray.end = ray.lineheight / 2 + coucou->win->height / 2;
	if (ray.start < 0)
		ray.start = 0;
	if (ray.end >= coucou->win->height)
		ray.end = coucou->win->height - 1;
	(void)ent;
	return (ray);
}

t_ray	ft_wolf_calc_hit_entity(t_ray ray, t_entity *ent, t_coucou *coucou)
{
	while (ray.hit == 0)
	{
		if (ray.sidedist.x < ray.sidedist.y)
		{
			ray.sidedist.x += ray.sidedist.x;
			ray.map.x += ray.step.x;
			ray.side = 0;
		}
		else
		{
			ray.sidedist.y += ray.sidedist.y;
			ray.map.y += ray.step.y;
			ray.side = 1;
		}
		ray.hit = (((int)ent->pos.x == ray.map.x) && ((int)ent->pos.y == ray.map.y)) ? 2 : 0;
		ray.hit = (coucou->map.world[ray.map.x][ray.map.y] > 0) ? 1 : 0;
	}
	if (ray.side == 0)
		ray.perpwalldist = (ray.map.x - ray.raypos.x + (1 - ray.step.x) / 2)
			/ ray.raydir.x;
	else
		ray.perpwalldist = (ray.map.y - ray.raypos.y + (1 - ray.step.y) / 2)
			/ ray.raydir.y;
	return (ft_wolf_calc_hit_entity2(ray, ent, coucou));
}

void	ft_entity_display_kappa(t_ray ray, t_core *core, int x, t_entity *e)
{
	t_point pts[2];
	t_entity_type	**type_mem;
	t_entity_type	*type;

	type_mem = &(core->coucou->entity_type);
	type = *type_mem;
	pts[0] = ft_create_point(ray.start, x);
	pts[1] = ft_create_point(ray.end, x);
	if (ray.hit == 2)
	{
		ft_printf("segv at %d\n", x);
		while (type->next)
		{
			if ((e->is_alive && e->type_id == type->type_id))
			{
				ft_wolf_display_texture(pts, ray, core->coucou->img, type->img);
				return ;
			}
			type = type->next;
		}
		if ((e->is_alive && e->type_id == type->type_id))
		{
			ft_wolf_display_texture(pts, ray, core->coucou->img, type->img);
			return ;
		}
	}
}

void	ft_entity_display(t_core *core)
{
	int			x;
	int			h;
	t_ray		ray;
	t_entity	**e_mem;
	t_entity	*e;

	x = core->min - 1;
	h = core->coucou->win->height;
	e_mem = &(core->coucou->entity);
	while (++x < core->max)
	{
		e = *e_mem;
		while (e->next)
		{
			ray = init_ray(core->coucou, x);
			ray = ft_wolf_calc_hit_entity(ray, e, core->coucou);
			ft_entity_display_kappa(ray, core, x, e);
			e = e->next;
		}
		ray = init_ray(core->coucou, x);
		ray = ft_wolf_calc_hit_entity(ray, e, core->coucou);
		ft_entity_display_kappa(ray, core, x, e);
	}
}
