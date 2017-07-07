/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:11:59 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/06 18:38:41 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_map		ft_get_map(char *name)
{
	t_map	map;
	int		i;

	map.get = ft_strnew(1);
	map.fd = open(name, O_RDONLY);
	i = 0;
	while (get_next_line(map.fd, &(map.gnl)) >= 1)
	{
		map.get = ft_free_join1(map.get, map.gnl);
		map.get = ft_free_join1(map.get, "\n");
		ft_strdel(&(map.gnl));
		i++;
	}
	close(map.fd);
	map.map = ft_strsplit(map.get, '\n');
	map.height = i;
	map.width = 0;
	map.world = (int **)malloc(sizeof(int *) * i);
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
			j++;
		map.width = j;
		map.world[i] = (int *)malloc(sizeof(int) * j);
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
