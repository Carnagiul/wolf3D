/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_calc3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:19:55 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/23 22:20:18 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			calc_sprite(t_coucou *coucou)
{
	pthread_t	thread[10];
	t_core		core[10];
	int			i;
	int			max;

	i = -1;
	max = coucou->win->width / 10;
	while (++i < 10)
	{
		core[i].coucou = coucou;
		core[i].min = max * i;
		core[i].max = max * (i + 1);
		pthread_create(&thread[i], NULL, (void*)ft_entity_display, &core[i]);
	}
	i = 0;
	while (i < 10)
		pthread_join(thread[i++], NULL);
}
