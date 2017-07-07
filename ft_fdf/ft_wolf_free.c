/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:07:56 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/06 19:07:57 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_texture(t_texture **texture)
{
	int		i;
	int		j;
	char	*path;
	char	*path2;
	t_file	*files;

	i = 0;
	path = ft_strdup("./textures/");
	files = ft_create_array_dir_wa(path);
	while (i < ft_files_count_dir_wa(path))
	{
		path2 = ft_string_join_path(path, files[i].name);
		j = 0;
		while (j++ < ft_files_count_dir_wa(path2))
		{
			free(texture[i][j].img);
			free(texture[i][j].name);
		}
		free(files[i].name);
		free(texture[i++]);
		free(path2);
	}
	free(files);
	free(path);
	free(texture);
}

void	free_map(t_map map)
{
	int i;

	free(map.gnl);
	free(map.get);
	i = 0;
	while (i < map.height)
	{
		if (map.map[i])
			free(map.map[i]);
		if (map.nb[i])
			free(map.nb[i]);
		if (map.world[i])
			free(map.world[i]);
		i++;
	}
	if (map.map)
		free(map.map);
	if (map.nb)
		free(map.nb);
	if (map.world)
		free(map.world);
}
