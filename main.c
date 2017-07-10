/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:54:44 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/10 05:23:05 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		load_itemlist(char **split, t_item **items, t_win *win)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (split[i])
	{
		if (split[i][0] != '#')
		{
			items[k] = get_item_id(k, split[i], win);
			k++;
		}
		i++;
	}
}

void		print_list_items(t_item **item_list, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		ft_printf("\n\n@RNew item found@@ :\n");
		ft_printf("\t@Pitem_id @@(@G%d@@)\n", item_list[i]->id);
		ft_printf("\t@Witem_type_id @@(@G%d@@)\n", item_list[i]->type_id);
		ft_printf("\t@Citem_amount_ammo @@(@G%d@@)\n", item_list[i]->amount_ammo);
		ft_printf("\t@Yitem_max_ammo @@(@G%d@@)\n", item_list[i]->max_ammo);
		ft_printf("\t@Bitem_name @@(@G%s@@)\n", item_list[i]->name);
		i++;
	}
}

t_item	**get_list_item(t_win *win)
{
	char		*item_content;
	char		**split;
	int			i;
	t_item		**item_list;
	int			count;

	item_content = ft_get_content_file("./ressources/item_list.wolf3d");
	split = ft_strsplit(item_content, '\n');
	ft_printf("\n\n@Rnb items@@ == %d\n\n", count_item_list(split));
	count = count_item_list(split);
	item_list = (t_item **)malloc(sizeof(t_item *) * count);
	if (!item_list)
	{
		ft_printf("Error: can't create list_item...\n");
		exit(0);
	}
	i = 0;
	load_itemlist(split, item_list, win);
	ft_strdel_array(split);
	print_list_items(item_list, count);
	free(item_content);
	return (item_list);
}

int	main(int argc, char **argv)
{
	t_item	**item;
	t_win	*win;

	win = ft_mlx_extended_gen_win(1280, 720, "wolf piquerue");
	if (win->win && win->mlx)
		item = get_list_item(win);
//	ft_wolf_init(argv);
	(void)argc;
	(void)argv;
	while (1) ;
	return (0);
}
