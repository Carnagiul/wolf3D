/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:20:27 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:36:56 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(char const *str, int c)
{
	int i;

	i = ft_strlen(str);
	while (i > 0 && str[i] != c)
		i--;
	if (str[i] == c)
		return ((char *)str + i);
	if (str[0] == c)
		return ((char *)str);
	return (NULL);
}
