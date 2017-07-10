/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_item_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 04:29:50 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/10 04:31:05 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		count_item_list(char **split)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (split[i])
	{
		if (split[i][0] == '#')
			k++;
		i++;
	}
	return (i - k);
}

int		is_valid_item(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return ((i == 14) ? 0 : 1);
}
