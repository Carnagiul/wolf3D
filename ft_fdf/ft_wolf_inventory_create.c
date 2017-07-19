/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_inventory_create.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 04:47:51 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 09:22:48 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_inventory		*ft_wolf_inventory_init(void)
{
	t_inventory	*inv;

	inv = (t_inventory *)malloc(sizeof(t_inventory));
	if (!inv)
	{
		ft_printf("Error: can't create inventory...\n");
		exit(0);
	}
	inv->slot1 = NULL;
	inv->slot2 = NULL;
	inv->slot3 = NULL;
	inv->slot4 = NULL;
	inv->slot5 = NULL;
	inv->actual_slot = 0;
	return (inv);
}
