/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_join_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 00:08:19 by piquerue          #+#    #+#             */
/*   Updated: 2017/06/01 03:16:26 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*ft_string_join_path(char *p1, char *p2)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!p1 || !p2)
		return (0);
	str = ft_strnew(ft_strlen(p1) + ft_strlen(p2) + 2);
	if (str)
	{
		while (*p1)
			str[i++] = *p1++;
		while (*p2)
			str[i++] = *p2++;
		str[i] = '\0';
	}
	return (str);
}
