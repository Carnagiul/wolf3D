/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 21:58:57 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:08:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_sprites			*ft_wolf_create_sprite(char *xpm, t_win *win,
		double x, double y)
{
	t_sprites *data;

	data = (t_sprites *)ft_malloc(sizeof(t_sprites));
	if (!data)
	{
		ft_printf("malloc error\n");
		exit(1);
	}
	data->pos = create_vector(x, y);
	data->next = NULL;
	data->img = ft_mlx_extended_gen_imgxpm(win, xpm);
	data->vmove = 0.0;
	return (data);
}

t_ray_sprites		ft_init_ray_sprites(t_coucou *coucou)
{
	t_ray_sprites	ray;

	ray.w = coucou->win->width;
	ray.h = coucou->win->height;
	return (ray);
}

void				print(t_ray_sprites ray, t_coucou *coucou,
		t_sprites *sprites, int y)
{
	ray.texture.y = ft_entity_get_texture_y(ray, sprites, y);
	coucou->img->img[ray.start.x * 4 + y * coucou->img->size_line] =
		sprites->img->img[ray.texture.x * 4 +
		ray.texture.y * sprites->img->size_line];
	coucou->img->img[ray.start.x * 4 + y * coucou->img->size_line + 1] =
		sprites->img->img[ray.texture.x * 4 +
		ray.texture.y * sprites->img->size_line + 1];
	coucou->img->img[ray.start.x * 4 + y * coucou->img->size_line + 2] =
		sprites->img->img[ray.texture.x * 4 +
		ray.texture.y * sprites->img->size_line + 2];
}

void				ft_entity_display(t_core *core)
{
	t_sprites		**mem_data;
	t_sprites		*sprites;
	t_ray_sprites	ray;
	int				y;

	ray = ft_init_ray_sprites(core->coucou);
	mem_data = &(core->coucou->sprite_list);
	sprites = *mem_data;
	while (sprites)
	{
		ray = ft_init_ray_sprite2(sprites, core->coucou, ray, core);
		while (ray.start.x < ray.end.x)
		{
			ray.texture.x = ft_entity_get_texture_x(ray, sprites);
			if (ray.transform.y > 0 && ray.start.x > 0 &&
					ray.transform.y < core->coucou->wall_dist[ray.start.x])
			{
				y = ray.start.y;
				while (y < ray.end.y)
					print(ray, core->coucou, sprites, y++);
			}
			ray.start.x++;
		}
		sprites = sprites->next;
	}
}
