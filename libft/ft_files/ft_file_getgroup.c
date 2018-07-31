/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_getgroup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 22:24:54 by piquerue          #+#    #+#             */
/*   Updated: 2018/05/18 22:24:55 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_file_getgroup(struct stat stat)
{
	char			*ret;
	t_group			*grp;

	ret = NULL;
	grp = getgrgid(stat.st_gid);
	if (grp)
		ret = ft_strdup(grp->gr_name);
	else
		ret = ft_itoa(stat.st_gid);
	if (ret != NULL)
		return (ret);
	return (ft_strdup("none"));
}
