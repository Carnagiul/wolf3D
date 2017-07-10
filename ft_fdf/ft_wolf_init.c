/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 11:34:43 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/10 00:50:15 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_player		ft_gen_player(void)
{
	t_player	p;

	p.move_up = 0;
	p.move_down = 0;
	p.move_left = 0;
	p.move_right = 0;
	p.move_speed = 0.1;
	p.rotate_speed = 0.05;
	p.in_menu_map = 0;
	p.in_config = 0;
	p.in_chat = 0;
	p.can_open = 0;
	p.message = ft_strdup("");
	return (p);
}

void			ft_wolf_init2(char **argv)
{
	int			i;
	char		*ret;

	i = 1;
	while (argv[i])
		i++;
	if (i < 2)
	{
		ft_printf("Error: ./wolf3d <filename.wolf3d> [-username]\n");
		exit(0);
	}
	ret = ft_get_extension(argv[1]);
	if (ft_strcmp(ret, "wolf3d") != 0)
	{
		ft_printf("Error: ./wolf3d <filename.wolf3d> [-username]\n");
		exit(0);
	}
	free(ret);
}

void			ft_wolf_init3(t_coucou *coucou)
{
	coucou->passage = 0;
	coucou->pos = create_vector(1.25, 1.26);
	coucou->dir = create_vector(-1, 0);
	coucou->plan = create_vector(0, 0.66);
	coucou->img = ft_mlx_extended_gen_img(coucou->win);
	coucou->p = ft_gen_player();
	coucou->texture = texturepack(coucou->win);
	coucou->texturepack = 0;
	update_texture(coucou);
	coucou->settings = ft_mlx_extended_gen_imgxpm(coucou->win,
			"./texture_win/settings.xpm");
	coucou->xmap = ft_mlx_extended_gen_imgxpm(coucou->win,
			"./texture_win/map.xpm");
	coucou->chat = ft_mlx_extended_gen_imgxpm(coucou->win,
			"./texture_win/chat.xpm");
}

void			ft_wolf_init(char **argv)
{
	int			d[2];
	t_coucou	*coucou;

	d[0] = 1280;
	d[1] = 720;
	ft_wolf_init2(argv);
	coucou = (t_coucou *)malloc(sizeof(t_coucou));
	coucou->map = ft_gen_world(argv[1]);
	if (verify_map(&(coucou->map)) == 1)
		exit(ft_printf("Error: bad file\n"));
	coucou->win = ft_mlx_extended_gen_win(d[0], d[1], "wolf piquerue");
	ft_wolf_init3(coucou);
	coucou->d = d[0];
	ft_printf("c\nc\n");
	mlx_hook(coucou->win->win, 2, (1L << 0), hooker, coucou);
	mlx_hook(coucou->win->win, 4, (1L << 2), mouse_click, coucou);
	mlx_hook(coucou->win->win, 3, (1L << 1), hooker_release, coucou);
	mlx_hook(coucou->win->win, 17, (1L << 17), red_cross, coucou);
	mlx_loop_hook(coucou->win->mlx, hooker2, coucou);
	mlx_loop(coucou->win->mlx);
}
