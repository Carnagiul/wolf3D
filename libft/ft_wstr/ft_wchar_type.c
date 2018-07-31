/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 22:19:09 by piquerue          #+#    #+#             */
/*   Updated: 2018/05/18 22:20:09 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_wstr_mappeur.h"

char		*ft_unix_string_get_name(int wc)
{
	int		j;

	j = 0;
	while (g_t_global_limit[j].min != -1)
	{
		if (g_t_global_limit[j].min <= wc && g_t_global_limit[j].max >= wc)
			return (g_t_global_limit[j].name);
		if (g_t_global_limit[j].min > wc)
			return (NULL);
		j++;
	}
	return (NULL);
}

int			ft_unix_char_is_valid(int wc)
{
	int		j;

	j = 0;
	while (g_t_global_limit[j].min != -1)
	{
		if (g_t_global_limit[j].min <= wc && g_t_global_limit[j].max >= wc)
			return (1);
		if (g_t_global_limit[j].min > wc)
			return (0);
		j++;
	}
	return (0);
}

void		ft_unix_string_display_put_struct(t_unix_char_limit l)
{
	int		min;
	int		max;

	min = l.min;
	max = l.max;
	while (min < max)
	{
		if (ft_unix_char_is_display_ii(min) == 1)
			ft_unix_string_display_ii(min);
		if (ft_unix_char_is_display_iii(min) == 1)
			ft_unix_string_display_iii(min);
		if (ft_unix_char_is_display_iv(min) == 1)
			ft_unix_string_display_iv(min);
		write(1, "\t", 1);
		min++;
	}
}

void		ft_unix_string_display_put(void)
{
	int		j;
	int		min;
	int		max;

	j = 0;
	min = 0;
	max = 0;
	while (g_t_global_limit[j].min != -1)
	{
		min = g_t_global_limit[j].min;
		max = g_t_global_limit[j].max;
		ft_printf("\nAffichage des characteres de %s (%#x >> %#x)\n",
			g_t_global_limit[j].name, min, max);
		ft_unix_string_display_put_struct(g_t_global_limit[j]);
		ft_printf("\nFin de l'Affichage des characteres de %s (%#x >> %#x)\n",
			g_t_global_limit[j].name, min, max);
		j++;
	}
}
