/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:54:44 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/09 05:31:18 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_content_file(char *file)
{
	int		fd;
	char	*content;
	char	*gnl;

	fd = open(file, O_RDONLY);
	if (fd >= 1)
	{
		content = ft_strnew(1);
		while (get_next_line(fd, &gnl))
		{
			content = ft_free_join1(content, gnl);
			content = ft_free_join1(content, "\n");
			ft_strdel(&gnl);
		}
		close(fd);
		return (content);
	}
	else
		ft_printf("Error: can't open this file... \n");
	return (NULL);
}

void	count_item_list(char **split)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (split[i])
	{
		if (split[i][0] == '#')
			k++;
		i++;
	}
	return (i - k);
}

int			is_valid_item(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	if (i == 14)
		return (0);
	return (1);
}

t_sound		*get_sound(char *sound_name, char *len)
{
	t_sound	*sound;

	sound = (t_sound *)malloc(sizeof(t_sound));
	if (!sound)
	{
		ft_printf("Error: can't create sound.\n");
		exit(0);
	}
	sound->len = ft_atoi(len);
	sound->sound = ft_strdup(sound_name);
	return (sound);
}

t_item		*get_item_id(int id, char *data_line)
{
	t_item	*item;
	char	**split;

	item = (t_item *)malloc(sizeof(t_item));
	split = ft_strsplit(data_line, '\t');
	if (is_valid_item(split) != 0 || !item)
	{
		ft_printf("Error: Can't create item id %d\n", id);
		exit(0);
	}
	item->id = ft_atoi(split[0]);
	item->type_id = ft_atoi(split[1]);
	item->amount_ammo = ft_atoi(split[2]);
	item->max_ammo = ft_atoi(split[3]);
	item->name = ft_strdup(split[4]);
	item->texture_name = ft_strdup(split[5]);
	//item->texture = load_texture(split[6]);
	item->size_actual = ft_atoi(split[7]);
	item->size_max = ft_atoi(split[8]);
	item->get_sound = get_sound(split[10], split[9]);
	item->drop_sound = get_sound(split[12], split[11]);
	item->user_sound = get_sound(split[14], split[13]);
	return (item);
}

void	get_list_item(void)
{
	char		*item_content;
	char		**split;
	int			i;
	t_item		**item_list;
	int			k;

	item_content - ft_get_content_file("./ressources/item_list.wolf3d");
	split = ft_strsplit(item_content, '\n');
	item_list = (t_item **)malloc(sizeof(t_item *) * count_item_list(split));
	if (!item_list)
	{
		ft_printf("Error: can't create list_item...\n");
		exit(0);
	}
	while (split[i])
	{
		if (split[i][0] != '#')
		{
			item_list[k] = get_item_id(k, split[i]);
			k++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
//	ft_wolf_init(argv);
	(void)argc;
	(void)argv;
	return (0);
}
