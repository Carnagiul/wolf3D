/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_array_files.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:51:39 by piquerue          #+#    #+#             */
/*   Updated: 2017/06/02 05:32:37 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_file		*ft_create_array_files_wa(char *path)
{
	int				nb;
	t_file			*files;
	struct dirent	*f;
	DIR				*dir;
	int				i;

	nb = ft_files_count_files_wa(path);
	files = (t_file *)malloc(sizeof(t_file) * nb);
	if (!files)
	{
		ft_printf("Erreur du malloc de ft_create_array_files_wa\n");
		exit(0);
	}
	i = 0;
	dir = opendir(path);
	while ((f = readdir(dir)) != NULL)
	{
		if (f->d_type != 4 && f->d_name[0] != '.')
		{
			files[i].name = ft_strdup(f->d_name);
			files[i++].type = f->d_type;
		}
	}
	closedir(dir);
	return (files);
}

t_file		*ft_create_array_dir_wa(char *path)
{
	int				nb;
	t_file			*files;
	struct dirent	*f;
	DIR				*dir;
	int				i;

	nb = ft_files_count_dir_wa(path);
	files = (t_file *)malloc(sizeof(t_file) * nb);
	if (!files)
	{
		ft_printf("Erreur du malloc de ft_create_array_files_wa\n");
		exit(0);
	}
	i = 0;
	dir = opendir(path);
	while ((f = readdir(dir)) != NULL)
	{
		if (f->d_type == 4 && f->d_name[0] != '.')
		{
			files[i].name = ft_strdup(f->d_name);
			files[i++].type = f->d_type;
		}
	}
	closedir(dir);
	return (files);
}
