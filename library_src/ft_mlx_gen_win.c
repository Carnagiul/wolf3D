/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_gen_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 01:26:30 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:22:15 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void		ft_mlx_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

t_win			*ft_mlx_extended_gen_win(int width, int height, char *name)
{
	t_win		*win;

	win = (t_win *)ft_malloc(sizeof(t_win));
	if (!win)
		ft_mlx_error("Erreur lors du malloc de win");
	win->mlx = mlx_init();
	if (!win->mlx)
	{
		free(win);
		ft_mlx_error("Erreur lors de l'initialisation de mlx");
	}
	win->win = mlx_new_window(win->mlx, width, height, name);
	if (!win->win)
	{
		free(win->mlx);
		free(win);
		ft_mlx_error("Erreur lors de l'initialisation de win_mlx");
	}
	win->x = (double)0;
	win->y = (double)0;
	win->width = width;
	win->height = height;
	win->name = name;
	return (win);
}
