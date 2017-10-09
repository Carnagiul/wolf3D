/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_create_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 23:50:49 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/17 23:55:27 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_color_mlx		create_color(int red, int green, int blue)
{
	t_color_mlx col;

	col.red = red;
	col.green = green;
	col.blue = blue;
	return (col);
}
