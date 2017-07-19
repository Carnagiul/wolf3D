/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_gen_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 01:29:51 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 06:15:07 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_mlx_error(char *str, t_win *win)
{
	free(win->win);
	free(win->mlx);
	free(win);
	ft_printf("%s\n", str);
	exit(1);
}

t_img		*ft_mlx_extended_gen_img(t_win *win)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		ft_mlx_error("Erreur lors de l'initialisation d'une image img", win);
	img->img_ptr = mlx_new_image(win->mlx, win->width, win->height);
	if (!img->img_ptr)
	{
		free(img);
		ft_mlx_error("Erreur lors de l'initialisation d'une image", win);
	}
	img->img = mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel),
			&(img->size_line), &(img->endian));
	if (!img->img)
	{
		free(img->img_ptr);
		free(img);
		ft_mlx_error("Erreur lors de la recuperation d'une image", win);
	}
	return (img);
}

t_img		*ft_mlx_extended_gen_imgxpm(t_win *win, char *name)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		ft_mlx_error("Erreur lors de l'initialisation d'une image", win);
	img->img_ptr = mlx_xpm_file_to_image(win->mlx, name, &(img->width),
			&(img->height));
	if (!img->img_ptr)
	{
		free(img);
		ft_mlx_error("Erreur lors de l'initialisation d'une image", win);
	}
	img->img = mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel),
			&(img->size_line), &(img->endian));
	if (!img->img)
	{
		free(img->img_ptr);
		free(img);
		ft_mlx_error("Erreur lors de la recuperation d'une image", win);
	}
	return (img);
}
