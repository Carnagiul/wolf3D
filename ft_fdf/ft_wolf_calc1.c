/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_calc1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:15:45 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/21 09:50:37 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_ray			calc_two(t_ray ray, t_coucou *coucou)
{
	ray.lineheight = (int)(coucou->win->height / ray.perpwalldist);
	ray.start = -ray.lineheight / 2 + coucou->win->height / 2;
	ray.end = ray.lineheight / 2 + coucou->win->height / 2;
	if (ray.start < 0)
		ray.start = 0;
	if (ray.end >= coucou->win->height)
		ray.end = coucou->win->height - 1;
	return (ray);
}

t_ray			calc_hit(t_ray ray, t_coucou *coucou)
{
	while (ray.hit == 0)
	{
		if (ray.sidedist.x < ray.sidedist.y)
		{
			ray.sidedist.x += ray.deltadist.x;
			ray.map.x += ray.step.x;
			ray.side = 0;
		}
		else
		{
			ray.sidedist.y += ray.deltadist.y;
			ray.map.y += ray.step.y;
			ray.side = 1;
		}
		ray.hit = (coucou->map.world[ray.map.x][ray.map.y] > 0) ? 1 : 0;
	}
	if (ray.side == 0)
		ray.perpwalldist = (ray.map.x - ray.raypos.x + (1 - ray.step.x) / 2)
			/ ray.raydir.x;
	else
		ray.perpwalldist = (ray.map.y - ray.raypos.y + (1 - ray.step.y) / 2)
			/ ray.raydir.y;
	return (calc_two(ray, coucou));
}

void			draw(t_ray ray, t_core *core, int x, int h)
{
	t_color_mlx	color;

	if (ray.start > 0)
		ft_mlx_draw_linept(ft_create_point(x, 0), ft_create_point(x, ray.start),
				core->coucou->img, create_color(0xFF, 0xFF, 0x00));
	if (ray.end < h)
		ft_mlx_draw_linept(ft_create_point(x, ray.start), ft_create_point(x, h),
				core->coucou->img, create_color(0x99, 0x99, 0x99));
	if (ray.side == 0)
		color = (ray.raydir.x >= 0) ? create_color(0xFF, 0, 0) :
			create_color(0x00, 0xFF, 0);
	else
		color = (ray.raydir.y >= 0) ? create_color(0, 0, 0xFF) :
			create_color(0xFF, 0, 0xFF);
	if (core->coucou->map.world[ray.map.x][ray.map.y] == 1)
		ft_wolf_display_texture_stonebrick(x,
				ft_create_point(ray.start, ray.end), core->coucou, ray);
	else if (core->coucou->map.world[ray.map.x][ray.map.y] == 2)
		ft_wolf_display_texture_woodenplanks(x,
				ft_create_point(ray.start, ray.end), core->coucou, ray);
	else
		ft_mlx_draw_linept(ft_create_point(x, ray.start),
				ft_create_point(x, ray.end), core->coucou->img, color);
}

void			calc(t_core *core)
{
	t_ray		ray;
	int			x;
	int			h;

	h = core->coucou->win->height;
	x = core->min;
	while (x < core->max)
	{
		ray = init_ray(core->coucou, x);
		ray = calc_hit(ray, core->coucou);
		draw(ray, core, x, h);
		core->coucou->wall_dist[x] = ray.perpwalldist;
		x++;
	}
}

void			calc_sprite(t_coucou *coucou)
{
	pthread_t	thread[10];
	t_core		core[10];
	int			i;
	int			max;

	i = -1;
	max = coucou->win->width / 10;
	while (++i < 10)
	{
		core[i].coucou = coucou;
		core[i].min = max * i;
		core[i].max = max * (i + 1);
		pthread_create(&thread[i], NULL, (void*)ft_entity_display, &core[i]);
	}
	i = 0;
	while (i < 10)
		pthread_join(thread[i++], NULL);
}

void			calc2(t_coucou *coucou)
{
	pthread_t	thread[4];
	t_core		core[4];
	int			i;
	int			max;

	i = -1;
	max = coucou->win->width / 4;
	while (++i < 4)
	{
		core[i].coucou = coucou;
		core[i].min = max * i;
		core[i].max = max * (i + 1);
		pthread_create(&thread[i], NULL, (void*)calc, &core[i]);
	}
	i = 0;
	while (i < 4)
		pthread_join(thread[i++], NULL);
	calc_sprite(coucou);
}
