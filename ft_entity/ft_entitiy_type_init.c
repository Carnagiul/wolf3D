/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_type_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 06:30:34 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/20 06:59:32 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_entity_type		*ft_entity_type_init(t_win *win)
{
	t_entity_type	*type;
	char			*content;
	int				i;
	char			**file_split;

	type = NULL;
	content = ft_get_content_file("./ressources/entity_type.wolf3d");
	file_split = ft_strsplit(content, '\n');
	i = 0;
	while (file_split[i])
	{
		if (file_split[i][0] != '#')
			ft_entity_type_add(&type, file_split[i]);
		i++;
	}
	ft_strdel_array(file_split);
	ft_strdel(&content);
	ft_entity_type_load(&type, win);
	return (type);
}
