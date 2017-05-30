/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_extended_load_texture.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:25:20 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/29 22:42:21 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_texture		**ft_load_texture(t_win *win)
{
	t_texture	**texture;

	texture = (t_texture **)malloc(sizeof(t_texture *) * 5);
	texture[0] = (t_texture *)malloc(sizeof(t_texture) * 2);
	texture[0][0].img = ft_mlx_extended_gen_imgxpm(win, "textures/32/brick.xpm");
	texture[0][1].img = ft_mlx_extended_gen_imgxpm(win, "textures/32/blue.xpm");
	texture[1] = (t_texture *)malloc(sizeof(t_texture) * 2);
	texture[1][0].img = ft_mlx_extended_gen_imgxpm(win, "textures/64/brick.xpm");
	texture[1][1].img = ft_mlx_extended_gen_imgxpm(win, "textures/64/blue.xpm");
	texture[2] = (t_texture *)malloc(sizeof(t_texture) * 2);
	texture[2][0].img = ft_mlx_extended_gen_imgxpm(win, "textures/128/brick.xpm");
	texture[2][1].img = ft_mlx_extended_gen_imgxpm(win, "textures/128/blue.xpm");
	texture[3] = (t_texture *)malloc(sizeof(t_texture) * 2);
	texture[3][0].img = ft_mlx_extended_gen_imgxpm(win, "textures/256/brick.xpm");
	texture[3][1].img = ft_mlx_extended_gen_imgxpm(win, "textures/256/blue.xpm");
	texture[4] = (t_texture *)malloc(sizeof(t_texture) * 2);
	texture[4][0].img = ft_mlx_extended_gen_imgxpm(win, "textures/tools/door.xpm");
	texture[4][1].img = ft_mlx_extended_gen_imgxpm(win, "textures/tools/door2.xpm");
	return (texture);
}
