/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:11:59 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 20:23:46 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_map		ft_get_map(char *name)
{
	t_map	map;
	int		i;

	map.get = ft_get_content_file(name);
	if ((map.fd = open(name, O_RDONLY)) <= 0)
		exit(0);
	i = 0;
	while (get_next_line(map.fd, &(map.gnl)) >= 1)
	{
		ft_strdel(&(map.gnl));
		i++;
	}
	close(map.fd);
	if (i <= 1)
		exit(0);
	map.map = ft_strsplit(map.get, '\n');
	map.height = i;
	map.width = 0;
	map.world = (int **)ft_malloc(sizeof(int *) * i);
	if (!map.world)
		exit(0);
	free(map.get);
	free(map.gnl);
	return (map);
}

void		ft_free_map_nb(t_map *map)
{
	int	j;

	j = 0;
	while (map->nb[j])
		free(map->nb[j++]);
	free(map->nb);
}

int			check_if_valid_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		map->nb = ft_strsplit(map->map[i], ' ');
		if (map->world[i][0] != 1 || map->world[i][map->width - 1] != 1)
			return (1);
		if (i == 0 || (i + 1) == map->height)
		{
			while (map->world[i][j] == 1)
				j++;
			if (j != map->width)
				return (1);
		}
		ft_free_map_nb(map);
		i++;
	}
	return (0);
}

int			verify_map(t_map *map)
{
	int		width;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (map->height < 3)
		exit(ft_printf("Error: Bad map file... vf_map\n"));
	map->nb = ft_strsplit(map->map[i++], ' ');
	while (map->nb[j])
		j++;
	width = j;
	ft_free_map_nb(map);
	while (i < map->height && map->map[i])
	{
		j = 0;
		map->nb = ft_strsplit(map->map[i], ' ');
		while (map->nb[j])
			j++;
		ft_free_map_nb(map);
		if (j != width)
			return (1);
		i++;
	}
	return (check_if_valid_map(map));
}

t_map		ft_gen_world(char *name)
{
	t_map	map;
	int		i;
	int		j;

	map = ft_get_map(name);
	i = 0;
	while (map.map[i])
	{
		j = 0;
		map.nb = ft_strsplit(map.map[i], ' ');
		while (map.nb[j])
			map.width = ++j;
		if (!(map.world[i] = (int *)ft_malloc(sizeof(int) * j)))
			exit(0);
		j = 0;
		while (map.nb[j])
		{
			map.world[i][j] = ft_atoi(map.nb[j]);
			j++;
		}
		j = 0;
		ft_free_map_nb(&map);
		i++;
	}
	return (map);
}
