/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_linept.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:06:50 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/29 23:08:22 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_mlx_draw_linept(t_point pt1, t_point pt2, t_img *img,
		t_color_mlx color)
{
	int cpy;

	cpy = pt1.y;
	while (pt1.x < pt2.x)
	{
		pt1.y = cpy;
		while (pt1.y < pt2.y)
		{
			ft_mlx_put_pixel_img(pt1.x, pt1.y, color, img);
			pt1.y++;
		}
		pt1.x++;
	}
}
