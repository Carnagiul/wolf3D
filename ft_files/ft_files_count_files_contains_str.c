/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_count_files_contains_str.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:34:54 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/29 23:56:46 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_files_count_files_contains_str(char *path, char *extension)
{
	struct dirent	*files;
	int count;
	DIR				*dir;
	char			**split;

	count = 0;
	dir = opendir(path);
	if (!dir)
		return (0);
	while ((files = readdir(dir)) != NULL)
	{
		if (files->d_type == 4)
		{
			split = ft_strsplit(files->d_name, '.');
			if (ft_strcmp(split[1], extension) == 0)
				count++;
		}
	}
	closedir(dir);
	return (count);
}
