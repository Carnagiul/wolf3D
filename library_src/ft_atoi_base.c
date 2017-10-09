/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:45:19 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 23:51:07 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_atoi_base_get_num(int base, char c)
{
	char	*base1;
	char	*base2;
	int		j;

	base1 = ft_strdup("0123456789ABCDEF");
	base2 = ft_strdup("0123456789abcdef");
	j = 0;
	while (j < base)
	{
		if (base1[j] == c)
			return (j);
		if (base2[j] == c)
			return (j);
		j++;
	}
	return (0);
}

int			ft_atoi_base(char *str, int base)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (str[i] != 0)
	{
		ret *= base;
		ret += ft_atoi_base_get_num(base, str[i]);
		i++;
	}
	return (ret);
}
