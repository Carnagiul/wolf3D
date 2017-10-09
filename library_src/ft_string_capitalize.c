/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_capitalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:10:03 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:35:57 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_string_capitalize(char *str)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			if (word == 0 && ft_char_isalpha_min(str[i]) == 1)
				str[i] -= 32;
			if (word == 1 && ft_char_isalpha_maj(str[i]) == 0)
				str[i] += 32;
			word = 1;
		}
		else
			word = 0;
		i++;
	}
	return (str);
}
