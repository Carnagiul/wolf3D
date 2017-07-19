/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_life_img_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 05:31:45 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 06:15:24 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_life_img		*ft_wolf_life_img_create2(int id, t_life_img *data, t_win *win)
{
	if (id == 10)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/50hp.xpm");
	else if (id == 11)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/45hp.xpm");
	else if (id == 12)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/40hp.xpm");
	else if (id == 13)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/35hp.xpm");
	else if (id == 14)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/30hp.xpm");
	else if (id == 15)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/25hp.xpm");
	else if (id == 16)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/20hp.xpm");
	else if (id == 17)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/15hp.xpm");
	else if (id == 18)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/10hp.xpm");
	else if (id == 19)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/5hp.xpm");
	else if (id == 20)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/0hp.xpm");
	return (data);
}

t_life_img		*ft_wolf_life_img_create3(int id, t_life_img *data, t_win *win)
{
	if (id == 0)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/100hp.xpm");
	else if (id == 1)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/95hp.xpm");
	else if (id == 2)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/90hp.xpm");
	else if (id == 3)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/85hp.xpm");
	else if (id == 4)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/80hp.xpm");
	else if (id == 5)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/75hp.xpm");
	else if (id == 6)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/70hp.xpm");
	else if (id == 7)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/65hp.xpm");
	else if (id == 8)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/60hp.xpm");
	else if (id == 9)
		data->img = ft_mlx_extended_gen_imgxpm(win, "./ressources/health/55hp.xpm");
	return (ft_wolf_life_img_create2(id, data, win));
}

t_life_img		*ft_wolf_life_img_create(int id, t_win *win)
{
	t_life_img	*data;

	data = (t_life_img *)malloc(sizeof(t_life_img));
	if (!data)
	{
		ft_printf("Error: Can't load t_life_data *\n");
		exit(0);
	}
	data->min = 100 - (id * 5);
	data->max = (id == 0) ? 100 : 100 - (id * 5) + 4;
	return (ft_wolf_life_img_create3(id, data, win));
}

t_life_img		**ft_wolf_life_img_init(t_win *win)
{
	t_life_img	**data;
	int			i;

	i = 0;
	data = (t_life_img **)malloc(sizeof(t_life_img *) * 20);
	if (!data)
	{
		ft_printf("Error: Can't load t_life_data **\n");
		exit(0);
	}
	while (i <= 20)
	{
		data[i] = ft_wolf_life_img_create(i, win);
		i++;
	}
	return (data);
}
