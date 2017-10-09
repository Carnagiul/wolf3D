/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_menu_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 05:12:28 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/07 02:56:11 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		calc_color(int color, int data2, int data1)
{
	int x;
	int	ratio;

	ratio = (data2 - data1) / 255;
	x = (color * ratio) + data1;
	return (x);
}

void	ft_line(t_point pt, t_fractol *fractol, int h, int i)
{
	t_point tmp;

	tmp = pt;
	tmp.y = h;
	while (pt.x < pt.y)
	{
		ft_pixel_put3(fractol, ft_create_point(pt.x, h), create_color(0x00,
					0xFF, 0x00));
		pt.x++;
	}
	if (i == 2)
		tmp.x = calc_color(fractol->color_bg.red, pt.y, tmp.x);
	if (i == 3)
		tmp.x = calc_color(fractol->color_bg.green, pt.y, tmp.x);
	if (i == 4)
		tmp.x = calc_color(fractol->color_bg.blue, pt.y, tmp.x);
	if (i == 10)
		tmp.x = calc_color(fractol->color_pt.red, pt.y, tmp.x);
	if (i == 11)
		tmp.x = calc_color(fractol->color_pt.green, pt.y, tmp.x);
	if (i == 12)
		tmp.x = calc_color(fractol->color_pt.blue, pt.y, tmp.x);
	ft_sphere(fractol, tmp, 5);
}

void	ft_zone(t_fractol *fractol, t_point a, t_point b, t_color_mlx col)
{
	t_point tmp;

	tmp = ft_create_point(a.x, a.y);
	while (tmp.x <= b.x)
	{
		tmp = ft_create_point(tmp.x, a.y);
		while (tmp.y <= b.y)
		{
			if (tmp.x == a.x || tmp.y == a.y || tmp.x == b.x || tmp.y == b.y)
				ft_pixel_put3(fractol, tmp, create_color(0xFF, 0xFF, 0xFF));
			else
				ft_pixel_put3(fractol, tmp, col);
			tmp.y++;
		}
		tmp.x++;
	}
}

void	ft_zone_maker(t_fractol *fractol)
{
	int l;
	int h;

	l = (fractol->win->width / 4);
	h = l * 3;
	ft_zone(fractol, ft_create_point(l / 5 + h, 5 * fractol->win->height / 19),
			ft_create_point((l - l / 5 + h), 9 * fractol->win->height / 19),
			fractol->color_bg);
	ft_zone(fractol, ft_create_point(l / 5 + h, 13 * fractol->win->height / 19),
			ft_create_point((l - l / 5 + h), 17 * fractol->win->height / 19),
			fractol->color_pt);
}

void	display_menu(t_fractol *fractol)
{
	t_point pt;
	int		h;
	int		l;

	l = (fractol->win->width / 4);
	h = 1;
	pt = ft_create_point(l * 3, 0);
	while (pt.x++ < fractol->win->width)
	{
		pt.y = 0;
		while (pt.y++ < fractol->win->height)
			ft_pixel_put(fractol, pt);
	}
	while (h++ <= 3)
		ft_line(ft_create_point((l * 0.1) + l * 3, (l * 0.9) + l * 3), fractol,
				((h * pt.y) / 19), h);
	h = 9;
	while (h++ <= 11)
		ft_line(ft_create_point((l * 0.1) + l * 3, (l * 0.9) + l * 3), fractol,
				((h * pt.y) / 19), h);
	ft_zone_maker(fractol);
}
