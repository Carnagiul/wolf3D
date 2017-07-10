/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_gen_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 00:40:06 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/10 01:29:23 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_texture		*ft_mlx_load_texture(char *file, t_win *win)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
	{
		ft_printf("Error: malloc can't create this texture...\n");
		exit(0);
	}
	texture->name = file;
	texture->img = ft_mlx_extended_gen_imgxpm(win, file);
	return (texture);
}
