/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_gettype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 22:25:03 by piquerue          #+#    #+#             */
/*   Updated: 2018/05/18 22:25:04 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				ft_display_file_type(struct stat stat)
{
	if ((stat.st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((stat.st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((stat.st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((stat.st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	if ((stat.st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	if ((stat.st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	return ('-');
}
