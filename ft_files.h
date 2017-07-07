/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:38:43 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/07 02:35:56 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILES_H
# define FT_FILES_H

typedef struct	s_file
{
	char		*name;
	int			type;
}				t_file;

int				ft_files_count_files(char *path);
int				ft_files_count_files_wa(char *path);

int				ft_files_count_dir(char *path);
int				ft_files_count_dir_wa(char *path);

int				ft_files_count_files_contains_str(char *path, char *extension);

t_file			*ft_create_array_files_wa(char *path);
t_file			*ft_create_array_dir_wa(char *path);

char			*ft_string_join_path(char *p1, char *p2);
#endif
