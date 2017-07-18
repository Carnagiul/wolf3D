/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:46:53 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/17 09:05:30 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			check_integrity_str(char *path, char *name, char *to_find)
{
	char		*filename;
	char		*content;
	char		**split;
	int			i;
	char		*ret;

	i = 0;
	filename = ft_strnew(1);
	filename = ft_free_join1(filename, path);
	filename = ft_free_join1(filename, "/");
	filename = ft_free_join1(filename, name);
	content = ft_get_content_file(filename);
	split = ft_strsplit(content, '\n');
	while (split[i])
	{
		ret = ft_strstr(split[i], to_find);
		if (ret)
			ft_printf("@R%s@@ ==> %s\n", name, split[i]);
		i++;
	}
	ft_strdel_array(split);
	ft_strdel(&content);
	ft_strdel(&filename);
}

void			ft_list_str_finder(char *path, char *to_find)
{
	t_file		*files;
	int			i;
	char		*ext;

	i = 0;
	files = ft_create_array_files_wa(path);
	while (i < ft_files_count_files_wa(path))
	{
		ext = ft_get_extension(files[i].name);
		if (ft_strcmp(ext, "c") == 0)
			check_integrity_str(path, files[i].name, to_find);
		ft_strdel(&ext);
		free(files[i].name);
		i++;
	}
	free(files);
}

void			ft_str_finder(char *path, char *to_find)
{
	char		*path2;
	t_file		*files;
	int			i;

	i = 0;
	files = ft_create_array_dir_wa(path);
	while (i < ft_files_count_dir_wa(path))
	{
		path2 = ft_strnew(1);
		path2 = ft_free_join1(path2, path);
		path2 = ft_free_join1(path2, "/");
		path2 = ft_free_join1(path2, files[i].name);
		ft_str_finder(path2, to_find);
		free(files[i].name);
		free(path2);
		i++;
	}
	free(files);
	ft_list_str_finder(path, to_find);
	return ;
}

void			ft_malloc_finder1(char *to_find)
{
	char		*path;

	path = ft_strdup(".");
	ft_printf("check all @R%s@@ ... \n", to_find);
	ft_str_finder(path, to_find);
	ft_printf("end of check all %s ..\n", to_find);
	free(path);
}
