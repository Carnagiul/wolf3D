/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 11:34:43 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/10 14:19:57 by piquerue         ###   ########.fr       */
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
	p.in_inventory = 0;
	p.is_god = 0;
	p.life = 100;
	p.playername = ft_strdup("George");
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
		ft_printf("Error: ./wolf3d <filename.wolf3d>\n");
		exit(0);
	}
	ret = ft_get_extension(argv[1]);
	if (ft_strcmp(ret, "wolf3d") != 0)
	{
		ft_printf("Error: ./wolf3d <filename.wolf3d>\n");
		exit(0);
	}
	free(ret);
}

t_vector		ft_wolf_spawn(t_coucou *coucou)
{
	int			i;
	int			j;

	i = 1;
	while (i < coucou->map.height)
	{
		j = 1;
		while (j < coucou->map.width)
		{
			if (coucou->map.world[i][j] == 0)
				return (create_vector((double)i + 0.25, (double)j + 0.26));
			j++;
		}
		i++;
	}
	ft_printf("can't genereate spawn...\n");
	exit(0);
}

void			ft_wolf_init3(t_coucou *coucou)
{
	coucou->passage = 0;
	coucou->pos = ft_wolf_spawn(coucou);
	coucou->dir = create_vector(-1, 0);
	coucou->plan = create_vector(0, 0.66);
	coucou->img = ft_mlx_extended_gen_img(coucou->win);
	coucou->p = ft_gen_player();
	coucou->texture = texturepack(coucou->win);
	coucou->texturepack = 0;
	coucou->list_items = get_list_item(coucou->win);
	update_texture(coucou);
	coucou->settings = ft_mlx_extended_gen_imgxpm(coucou->win,
			"./texture_win/settings.xpm");
	coucou->xmap = ft_mlx_extended_gen_imgxpm(coucou->win,
			"./texture_win/map.xpm");
	coucou->chat = ft_mlx_extended_gen_imgxpm(coucou->win,
			"./texture_win/chat.xpm");
	coucou->life = ft_wolf_life_img_init(coucou->win);
	coucou->play_sound = 1;
	coucou->entity_type = ft_entity_type_init(coucou->win);
	coucou->entity = NULL;
	coucou->wall_dist = ft_utils_init_double_array(coucou->win->width);
	coucou->sprite_list =
		ft_wolf_create_sprite("./ressources/entity/skeleton.xpm",
				coucou->win, 1.23, 1.42);
	coucou->sprite_list->next = NULL;
}

void			ft_wolf_init(int argc, char **argv)
{
	int			*d;
	t_coucou	*coucou;

	ft_wolf_init2(argv);
	coucou = (t_coucou *)ft_malloc(sizeof(t_coucou));
	if (!coucou)
		exit(ft_printf("Error: can't create coucou...\n"));
	d = ft_mlx_extended_parser(argc, argv);
	coucou->map = ft_gen_world(argv[1]);
	if (verify_map(&(coucou->map)) == 1)
		exit(ft_printf("Error: bad file\n"));
	coucou->win = ft_mlx_extended_gen_win(d[0], d[1], "wolf piquerue");
	ft_wolf_init3(coucou);
	coucou->d = d[0];
	free(d);
	coucou->playlist = NULL;
	coucou->playlist = ft_playlist_load();
	ft_printf("c\nc\n");
	mlx_hook(coucou->win->win, 2, (1L << 0), hooker, coucou);
	mlx_hook(coucou->win->win, 4, (1L << 2), mouse_click, coucou);
	mlx_hook(coucou->win->win, 3, (1L << 1), hooker_release, coucou);
	mlx_hook(coucou->win->win, 17, (1L << 17), red_cross, coucou);
	mlx_loop_hook(coucou->win->mlx, hooker2, coucou);
	mlx_loop(coucou->win->mlx);
}
