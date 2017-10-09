/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_struct_next.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 04:34:03 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 04:36:06 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long long		ft_pow_llu(t_itoa *itoa)
{
	unsigned long long	pow;
	unsigned long long	nbr;

	nbr = itoa->nbr;
	pow = 0;
	while (nbr >= (unsigned long long)itoa->base_len)
	{
		nbr /= itoa->base_len;
		++pow;
	}
	return (++pow);
}

void					ft_gen_base(t_itoa *itoa)
{
	char				*base;
	int					i;

	i = 0;
	base = ft_strnew(itoa->base_len);
	while (i < itoa->base_len)
	{
		if (i > 9)
		{
			if (itoa->is_maj == 1)
				base[i] = 'A' + (i - 10);
			else
				base[i] = 'a' + (i - 10);
		}
		else
			base[i] = '0' + i;
		i++;
	}
	base[i] = '\0';
	itoa->base = base;
}
