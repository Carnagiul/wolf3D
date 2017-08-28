/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_display_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 21:55:38 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/23 21:57:00 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector			ft_get_sprite_pos(t_sprites *sprites, t_coucou *coucou)
{
	t_vector		vector;

	vector.x = sprites->pos.x - coucou->pos.x;
	vector.y = sprites->pos.y - coucou->pos.y;
	return (vector);
}

t_ray_sprites		ft_calc_start_end(t_ray_sprites ray, t_core *core)
{
	ray.start.y = -ray.sprite_data.y / 2 + ray.h / 2 + ray.screen_data.y;
	ray.start.x = -ray.sprite_data.x / 2 + ray.screen_data.x;
	if (ray.start.x < core->min)
		ray.start.x = core->min;
	if (ray.start.y < 0)
		ray.start.y = 0;
	ray.end.y = ray.sprite_data.y / 2 + ray.h / 2 + ray.screen_data.y;
	ray.end.x = ray.sprite_data.x / 2 + ray.screen_data.x;
	if (ray.end.x > core->max)
		ray.end.x = core->max;
	if (ray.end.y > ray.h)
		ray.end.y = ray.h;
	return (ray);
}

t_ray_sprites		ft_init_ray_sprite2(t_sprites *sprites, t_coucou *coucou,
		t_ray_sprites ray, t_core *core)
{
	ray.sprite = ft_get_sprite_pos(sprites, coucou);
	ray.invdet = 1.0 / (coucou->plan.x * coucou->dir.y -
			coucou->dir.x * coucou->plan.y);
	ray.transform.x = ray.invdet * (coucou->dir.y * ray.sprite.x -
			coucou->dir.x * ray.sprite.y);
	ray.transform.y = ray.invdet * (-coucou->plan.y * ray.sprite.x +
			coucou->plan.x * ray.sprite.y);
	ray.screen_data.x = (int)((ray.w / 2) *
			(1 + ray.transform.x / ray.transform.y));
	ray.screen_data.y = (int)0.0 / ray.transform.y;
	ray.sprite_data.x = abs((int)(ray.h / (ray.transform.y))) / 1;
	ray.sprite_data.y = abs((int)(ray.h / (ray.transform.y))) / 1;
	ray = ft_calc_start_end(ray, core);
	return (ray);
}

int					ft_entity_get_texture_x(t_ray_sprites ray,
		t_sprites *sprites)
{
	int				pos;

	pos = (256 * (ray.start.x - (-ray.sprite_data.x / 2 + ray.screen_data.x))
			* sprites->img->width / ray.sprite_data.x) / 256;
	return (pos);
}

int					ft_entity_get_texture_y(t_ray_sprites ray,
		t_sprites *sprites, int y)
{
	int				calc0;
	int				pos;

	calc0 = (y - ray.screen_data.y) * 256 - ray.h * 128 +
		ray.sprite_data.y * 128;
	pos = ((calc0 * sprites->img->height) / ray.sprite_data.y) / 256;
	return (pos);
}
