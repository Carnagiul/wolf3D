/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 23:35:28 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/29 23:27:24 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_pixel_put(t_fractol *fractol, t_point pt)
{
	int chute;

	chute = (pt.x * 4) + (pt.y * fractol->img->size_line);
	fractol->img->img[chute] = 255;
	fractol->img->img[++chute] = 120;
	fractol->img->img[++chute] = 0;
	fractol->img->img[++chute] = 90;
}

void	ft_pixel_put3(t_fractol *fractol, t_point pt, t_color_mlx color)
{
	int chute;

	chute = (pt.x * 4) + (pt.y * fractol->img->size_line);
	fractol->img->img[chute] = color.red;
	fractol->img->img[++chute] = color.green;
	fractol->img->img[++chute] = color.blue;
	fractol->img->img[++chute] = 90;
}

void	ft_sphere(t_fractol *fractol, t_point pt, int r)
{
	t_point tmp;

	tmp = pt;
	tmp.y -= r;
	while (tmp.y <= pt.y + r)
	{
		tmp.x = pt.x - r;
		while (tmp.x <= pt.x + r)
		{
			if (r * r >= ft_power(tmp.x - pt.x, 2) + ft_power(tmp.y - pt.y, 2))
				ft_pixel_put3(fractol, tmp, create_color(0x00, 0xFF, 0x00));
			tmp.x++;
		}
		tmp.y++;
	}
}
