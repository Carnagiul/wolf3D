/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_getuser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 22:25:14 by piquerue          #+#    #+#             */
/*   Updated: 2018/05/18 22:25:14 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_file_getuser(struct stat stat)
{
	char			*ret;
	t_pswd			*pswd;

	ret = NULL;
	pswd = getpwuid(stat.st_uid);
	if (pswd)
		ret = ft_strdup(pswd->pw_name);
	else
		ret = ft_itoa(stat.st_uid);
	if (ret != NULL)
		return (ret);
	return (ft_strdup("none"));
}
