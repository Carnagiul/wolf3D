/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:31:00 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:31:43 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_pow_base(int nb, int base)
{
	int				b;
	int				pow;

	pow = 0;
	b = nb;
	while (b != 0)
	{
		pow++;
		b /= base;
	}
	if (nb < 0 && base == 10)
		pow++;
	return (pow);
}

static char			*ft_base(int base)
{
	char			*str;
	int				start;
	int				k;

	str = (char *)malloc(sizeof(char) * base);
	k = 0;
	start = -1;
	while (++start <= 9 && base-- >= 0)
		str[start] = '0' + start;
	while (base-- >= 0)
		str[start++] = 'A' + k++;
	return (str);
}

static char			*ft_check_it(char *str, char *base_str, int nb, int base)
{
	int				n;
	int				i;

	n = nb;
	if (nb == 0)
		return ("0");
	i = ft_pow_base(nb, base);
	str[i--] = '\0';
	if (n == -2147483648 && base == 10)
		return ("-2147483648");
	if (n < 0)
		n = -n;
	while (n > base - 1)
	{
		str[i--] = base_str[(n % base)];
		n = n / base;
	}
	str[i--] = base_str[n % base];
	if (nb < 0 && base == 10)
		str[i--] = '-';
	return (str);
}

char				*ft_itoa_base(int nb, int base)
{
	char			*str;
	int				n;
	char			*base_str;

	if (base >= 2 && base <= 16)
		base_str = ft_base(base);
	else
		return ("");
	n = nb;
	str = (char *)malloc(sizeof(char) * (ft_pow_base(nb, base) + 1));
	if (!str)
		return (0);
	if (str)
		str = ft_check_it(str, base_str, nb, base);
	return (str);
}
