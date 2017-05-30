/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_put_pixel_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:08:42 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/29 23:09:25 by piquerue         ###   ########.fr       */
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
