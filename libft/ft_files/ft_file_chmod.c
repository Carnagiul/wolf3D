/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_chmod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 22:24:46 by piquerue          #+#    #+#             */
/*   Updated: 2018/05/18 22:24:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_file_chmod(struct stat stat)
{
	char			*ret;

	ret = ft_malloc(sizeof(char) * 10);
	ret[0] = (stat.st_mode & S_IRUSR) ? 'r' : '-';
	ret[1] = (stat.st_mode & S_IWUSR) ? 'w' : '-';
	ret[2] = (stat.st_mode & S_IXUSR) ? 'x' : '-';
	if (stat.st_mode & S_ISUID)
		ret[2] = (stat.st_mode & S_IXUSR) ? 's' : 'S';
	ret[3] = (stat.st_mode & S_IRGRP) ? 'r' : '-';
	ret[4] = (stat.st_mode & S_IWGRP) ? 'w' : '-';
	ret[5] = (stat.st_mode & S_IXGRP) ? 'x' : '-';
	if (stat.st_mode & S_ISGID)
		ret[5] = (stat.st_mode & S_IXGRP) ? 's' : 'S';
	ret[6] = (stat.st_mode & S_IROTH) ? 'r' : '-';
	ret[7] = (stat.st_mode & S_IWOTH) ? 'w' : '-';
	ret[8] = (stat.st_mode & S_IXOTH) ? 'x' : '-';
	if (stat.st_mode & S_ISVTX)
		ret[8] = (stat.st_mode & S_IXOTH) ? 't' : 'T';
	ret[9] = '\0';
	return (ret);
}
