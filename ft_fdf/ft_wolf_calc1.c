/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_calc1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:15:45 by piquerue          #+#    #+#             */
/*   Updated: 2017/06/02 04:25:44 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	calc(t_core *core)
{
	t_ray	ray;
	t_color_mlx color;

	int h = core->coucou->win->height;
	for(int x = core->min; x < core->max; x++)
	{
		ray = init_ray(core->coucou, x);

		ray.hit = 0;
		ray.side = 0;
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
			if (core->coucou->map.world[ray.map.x][ray.map.y] > 0) ray.hit = 1;
		}
		if (ray.side == 0) ray.perpWallDist = (ray.map.x - ray.raypos.x + (1 - ray.step.x) / 2) / ray.raydir.x;
		else           ray.perpWallDist = (ray.map.y - ray.raypos.y + (1 - ray.step.y) / 2) / ray.raydir.y;

		ray.lineheight = (int)(h / ray.perpWallDist);
		ray.start = -ray.lineheight / 2 + h / 2;
		ray.end = ray.lineheight / 2 + h / 2;
		if(ray.start < 0)
			ray.start = 0;
		if(ray.end >= h)
			ray.end = h - 1;

		if (ray.start > 0)
			verLine(x, 0, ray.start, create_color(0x00, 0xFF, 0xFF), core->coucou);
		if (ray.end < h)
			verLine(x, ray.start, h, create_color(0x99, 0x99, 0x99), core->coucou);
		if (ray.side == 0)
			color = (ray.raydir.x >= 0) ? create_color(0xFF, 0, 0) : create_color(0x00, 0xFF, 0);
		else
			color = (ray.raydir.y >= 0) ? create_color(0, 0, 0xFF) : create_color(0xFF, 0, 0xFF);
		if (core->coucou->map.world[ray.map.x][ray.map.y] == 1)
			ft_wolf_display_texture_stonebrick(x, ray.start, ray.end, core->coucou, ray);
		else if (core->coucou->map.world[ray.map.x][ray.map.y] == 2)
			ft_wolf_display_texture_woodenplanks(x, ray.start, ray.end, core->coucou, ray);
		else
			verLine(x, ray.start, ray.end, color, core->coucou);
	}
}

void	calc2(t_coucou *coucou)
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
}

void	calc_menu(t_coucou *coucou)
{
	int h;
	int w;
	int	i;
	int	j;
	t_point	pt[2];

	w = coucou->win->width / (2 + coucou->map.width);
	h = coucou->win->height / (2 + coucou->map.height);
	i = 0;
	while (i < coucou->map.height)
	{
		j = 0;
		while (j < coucou->map.width)
		{
			pt[0].x = (j + 1) * w;
			pt[1].x = (j + 2) * w;
			pt[0].y = (i + 1) * h;
			pt[1].y = (i + 2) * h;
			if (coucou->map.world[i][j] == 0 && j == (int)coucou->pos.y && i == (int)coucou->pos.x)
				ft_mlx_draw_linept(pt[0], pt[1], coucou->img,
						create_color(0, 0, 255));
			else if (coucou->map.world[i][j] == 0)
				ft_mlx_draw_linept(pt[0], pt[1], coucou->img,
						create_color(255, 255, 255));
			else if (coucou->map.world[i][j] == 2)
				ft_mlx_draw_linept(pt[0], pt[1], coucou->img,
						create_color(0, 150, 0));
			else
				ft_mlx_draw_linept(pt[0], pt[1], coucou->img,
						create_color(30, 30, 30));
			j++;
		}
		i++;
	}
}
