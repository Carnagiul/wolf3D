/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_init_double_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 06:36:34 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/21 06:38:52 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double		*ft_utils_init_double_array(int rows)
{
	double	*array;
	int		i;

	array = (double *)malloc(sizeof(double) * rows);
	if (!array)
	{
		ft_printf("Error: can't malloc double array *\n");
		exit(0);
	}
	i = 0;
	while (i < rows)
		array[i++] = 0.0;
	return (array);
}
