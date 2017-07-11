/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_content_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 02:15:42 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/11 01:05:26 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_get_content_file(char *file)
{
	int		fd;
	char	*content;
	char	*gnl;

	fd = open(file, O_RDONLY);
	if (fd >= 1)
	{
		content = ft_strnew(1);
		while (get_next_line(fd, &gnl) == 1)
		{
			content = ft_free_join1(content, gnl);
			content = ft_free_join1(content, "\n");
			ft_strdel(&gnl);
		}
		close(fd);
		return (content);
	}
	ft_printf("Error: can't open the file @R%s@@\n", file);
	return (NULL);
}
