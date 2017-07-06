/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_calc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 19:01:32 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/05 19:17:21 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			ft_part1(t_point pt[2], t_coucou *coucou, t_color_mlx color)
{
	ft_mlx_draw_linept(pt[0], pt[1], coucou->img, color);
}

void			ft_part0(t_point pt[2], t_coucou *coucou, int i, int j)
{
	if (coucou->map.world[i][j] == 0 && j == (int)coucou->pos.y &&
			i == (int)coucou->pos.x)
		ft_part1(pt, coucou, create_color(0, 0, 255));
	else if (coucou->map.world[i][j] == 0)
		ft_part1(pt, coucou, create_color(255, 255, 255));
	else if (coucou->map.world[i][j] == 2)
		ft_part1(pt, coucou, create_color(0, 150, 0));
	else
		ft_part1(pt, coucou, create_color(30, 30, 30));
}

void			calc_menu(t_coucou *coucou)
{
	int			h;
	int			w;
	int			i;
	int			j;
	t_point		pt[2];

	w = coucou->win->width / (2 + coucou->map.width);
	h = coucou->win->height / (2 + coucou->map.height);
	i = -1;
	while (++i < coucou->map.height)
	{
		j = -1;
		while (++j < coucou->map.width)
		{
			pt[0].x = (j + 1) * w;
			pt[1].x = (j + 2) * w;
			pt[0].y = (i + 1) * h;
			pt[1].y = (i + 2) * h;
			ft_part0(pt, coucou, i, j);
		}
	}
}
