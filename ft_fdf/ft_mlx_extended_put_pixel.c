/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_extended_put_pixel.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 03:28:20 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/05 00:17:21 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_mlx_put_pixel_img(int x, int y, t_color_mlx color, t_img *img)
{
	int data;

	data = x * 4 + img->size_line * y;
	img->img[data] = color.red;
	img->img[++data] = color.green;
	img->img[++data] = color.blue;
}

void	ft_mlx_extended_put_pixel(t_img *img, int x, int y, t_color_mlx color)
{
	int data;

	data = (x * 4) + (y * img->size_line);
	img->img[data] = color.red;
	img->img[++data] = color.green;
	img->img[++data] = color.blue;
}

void	ft_mlx_draw_linept(t_point pt1, t_point pt2, t_img *img,
		t_color_mlx color)
{
	int cpy;

	cpy = pt1.y;
	while (pt1.x <= pt2.x)
	{
		pt1.y = cpy;
		while (pt1.y <= pt2.y)
		{
			ft_mlx_put_pixel_img(pt1.x, pt1.y, color, img);
			pt1.y++;
		}
		pt1.x++;
	}
}
