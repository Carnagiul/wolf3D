/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:57:29 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:31:42 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_itoa(int nb)
{
	char	*str;
	int		n;
	int		i;

	n = nb;
	str = (char *)malloc(sizeof(char) * (ft_pow(nb) + 1));
	if (!str)
		return (ft_strdup("0"));
	if (nb == 0)
		return (ft_strdup("0"));
	i = ft_pow(nb);
	str[i--] = '\0';
	if (-2147483648 == nb)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		str[i--] = '0' + (n % 10);
		n = n / 10;
	}
	if (nb < 0)
		str[i--] = '-';
	return (str);
}
