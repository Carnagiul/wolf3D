/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_extended_put_pixel.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 03:28:20 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/29 03:33:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_mlx_extended_put_pixel(t_img *img, int x, int y, t_color_mlx color)
{
	int data;

	data = (x * 4) + (y * img->size_line);
	img->img[data] = color.red;
	img->img[++data] = color.green;
	img->img[++data] = color.blue;
}

