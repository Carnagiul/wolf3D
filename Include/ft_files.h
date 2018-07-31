/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:05:01 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/19 00:06:09 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILES_H
# define FT_FILES_H

typedef struct passwd	t_pswd;
typedef struct group	t_group;
typedef struct stat	t_stat;

int						ft_files_count_dir(char *path);
int						ft_files_count_dir_wa(char *path);
int						ft_files_count_files(char *path);
int						ft_files_count_files_wa(char *path);
int						ft_files_count_files_contains_str(char *path,
						char *extension);
char					*ft_file_getgroup(struct stat stat);
char					*ft_file_chmod(struct stat stat);
void					ft_file_gettime(time_t timestamp);
char					ft_display_file_type(struct stat stat);
char					*ft_file_getuser(struct stat stat);
char					*ft_joinpath(char *s1, char *s2);

#endif
