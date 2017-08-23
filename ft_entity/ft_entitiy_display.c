/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 07:45:07 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/21 10:19:04 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

typedef struct	s_ray_sprites
{
	int					h;
	int					w;
	int					min;
	int					max;
	double				perpwalldist;
	struct s_vector		sprite;
	struct s_vector		transform;
	double				invdet;
	struct s_point		start;
	struct s_point		end;
	struct s_point		sprite_data;
	struct s_point		screen_data;
	struct s_point		texture;
}						t_ray_sprites;

typedef struct				s_raysprites
{
	struct s_vector			pos;
	struct s_vector			transform;
	double					invdet;
	double					vmove;
	struct s_point			screen;
	struct s_point			start;
	struct s_point			end;
	struct s_point			data;
}							t_raysprites;

t_sprites			*ft_wolf_create_sprite(char *xpm, t_win *win, double x, double y)
{
	t_sprites *data;

	data = (t_sprites *)malloc(sizeof(t_sprites));
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

void			ft_entity_display(t_core *core)
{
	t_sprites	**mem_data;
	t_sprites	*sprites;
	t_coucou	*coucou;

	coucou = core->coucou;
	mem_data = &(coucou->sprite_list);
	int w = 1280;
	int h = 720;
	sprites = *mem_data;
	while (sprites)
	{
		double spriteX = sprites->pos.x - coucou->pos.x;
		double spriteY = sprites->pos.y - coucou->pos.y;
		double invDet = 1.0 / (coucou->plan.x * coucou->dir.y - coucou->dir.x * coucou->plan.y);
		double transformX = invDet * (coucou->dir.y * spriteX - coucou->dir.x * spriteY);
		double transformY = invDet * (-coucou->plan.y * spriteX + coucou->plan.x * spriteY);
		int spriteScreenX = (int)((coucou->win->width / 2) * (1 + transformX / transformY));
#define uDiv 1
#define vDiv 1
#define vMove 0.0
		int vMoveScreen = (int)(vMove / transformY);
		int spriteHeight = abs((int)(coucou->win->height / (transformY))) / vDiv;
		int drawStartY = -spriteHeight / 2 + h / 2 + vMoveScreen;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + h / 2 + vMoveScreen;
		if(drawEndY >= h) drawEndY = h - 1;

		int spriteWidth = abs( (int) (h / (transformY))) / uDiv;
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= w) drawEndX = w - 1;
		if (drawStartX < core->min)
			drawStartX = core->min;
		if (drawEndX > core->max)
			drawEndX = core->max;
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * sprites->img->width / spriteWidth) / 256;
			if(transformY > 0 && stripe > 0 && stripe < w && transformY < coucou->wall_dist[stripe])
			{
				for(int y = drawStartY; y < drawEndY; y++)
				{
					int c = 0;
					int d = (y-vMoveScreen) * 256 - h * 128 + spriteHeight * 128;
					int texY = ((d * sprites->img->height) / spriteHeight) / 256;
					if (sprites->img->img[texX * 4 + texY * sprites->img->size_line] == 0)
						if (sprites->img->img[texX * 4 + texY * sprites->img->size_line + 1] == 0)
							if (sprites->img->img[texX * 4 + texY * sprites->img->size_line + 2] == 0)
								c = 1;
					if (c == 0)
					{
						coucou->img->img[stripe * 4 + y * coucou->img->size_line] = sprites->img->img[texX * 4 + texY * sprites->img->size_line];
						coucou->img->img[stripe * 4 + y * coucou->img->size_line + 1] = sprites->img->img[texX * 4 + texY * sprites->img->size_line + 1];
						coucou->img->img[stripe * 4 + y * coucou->img->size_line + 2] = sprites->img->img[texX * 4 + texY * sprites->img->size_line + 2];
						coucou->img->img[stripe * 4 + y * coucou->img->size_line + 3] = sprites->img->img[texX * 4 + texY * sprites->img->size_line + 3];
					}
				}
			}
		}
		sprites = sprites->next;
	}
}

