/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_gettime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 22:24:59 by piquerue          #+#    #+#             */
/*   Updated: 2018/05/18 22:25:00 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_file_gettime(time_t timestamp)
{
	time_t			t;
	char			*dt;

	dt = ctime(&timestamp);
	t = time(NULL);
	if (t - timestamp <= 15811200)
		ft_printf("%2.2s %3.3s %5.5s ", &(dt[8]), &(dt[4]), &(dt[11]));
	else
		ft_printf("%2.2s %3.3s %5.4s ", &(dt[8]), &(dt[4]), &(dt[20]));
}
