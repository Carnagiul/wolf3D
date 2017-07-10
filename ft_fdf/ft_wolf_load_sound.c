/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_load_sound.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 04:20:41 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/10 04:23:44 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_sound		*ft_wolf_load_sound(char *sound_name, char *len)
{
	t_sound	*sound;

	sound = (t_sound *)malloc(sizeof(t_sound));
	if (!sound)
	{
		ft_printf("Error: can't load the sound %s\n", sound_name);
		exit(0);
	}
	sound->len = ft_atoi(len);
	sound->sound = sound_name;
	return (sound);
}
