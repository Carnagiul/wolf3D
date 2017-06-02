/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 03:12:30 by piquerue          #+#    #+#             */
/*   Updated: 2017/06/02 03:29:59 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_open_menu_config(t_coucou *coucou)
{
	int		split;
	int		i;
	t_point	pt[2];

	split = coucou->win->height;
	split /= (ft_files_count_dir_wa("./textures/") + 2);
	i = 0;
	while (i < ft_files_count_dir_wa("./textures/"))
	{
		pt[0].x = coucou->win->width / 2;
		pt[1].x = coucou->win->width - 1;
		pt[0].y = (i + 1) * split;
		pt[1].y = (i + 2) * split;
		if (coucou->texturepack == i)
			ft_mlx_draw_linept(pt[0], pt[1], coucou->img,
					create_color(0x0, 0x0, 0xFF));
		else
			ft_mlx_draw_linept(pt[0], pt[1], coucou->img,
					create_color(0xFF, 0xFF, 0xFF));
		i++;
	}
	coucou->win->width /= 2;
	calc2(coucou);
	coucou->win->width *= 2;
}
