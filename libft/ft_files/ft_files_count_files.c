/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_count_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:33:42 by piquerue          #+#    #+#             */
/*   Updated: 2017/06/02 05:31:30 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_files_count_files(char *path)
{
	struct dirent	*files;
	int				count;
	DIR				*dir;

	count = 0;
	dir = opendir(path);
	if (!dir)
		return (0);
	while ((files = readdir(dir)) != NULL)
	{
		if (files->d_type != 4)
			count++;
	}
	free(files);
	closedir(dir);
	return (count);
}

int		ft_files_count_files_wa(char *path)
{
	struct dirent	*files;
	int				count;
	DIR				*dir;

	count = 0;
	dir = opendir(path);
	if (!dir)
		return (0);
	while ((files = readdir(dir)) != NULL)
	{
		if (files->d_type != 4 && files->d_name[0] != '.')
			count++;
	}
	free(files);
	closedir(dir);
	return (count);
}
