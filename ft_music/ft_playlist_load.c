/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playlist_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 03:58:28 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/18 08:14:18 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*parse_media_file(char *filename)
{
	char		**media;
	int			i;
	char		*ret;

	media = ft_strsplit(filename, '_');
	i = 0;
	while (media[i])
		i++;
	if (i != 2)
	{
		ft_printf("Error: can't load the sound %s\n", filename);
		exit(0);
	}
	ret = ft_strdup(media[0]);
	ft_strdel_array(media);
	return (ret);
}

t_playlist		*ft_playlist_load(void)
{
	t_playlist	*list;
	char		*duration;
	t_file		*files;
	int			i;
	char		*ext;

	if (!(files = ft_create_array_files_wa("./ressources/music/")))
		exit(ft_printf("Error: malloc ft_playlist_load\n"));
	i = -1;
	while (++i < ft_files_count_files_wa("./ressources/music/"))
	{
		ext = ft_get_extension(files[i].name);
		if (ft_strcmp(ext, "mp3") == 0)
		{
			duration = parse_media_file(files[i].name);
			ft_playlist_add_sound(&list, ft_sound_create(duration,
						files[i].name));
			free(files[i].name);
			ft_strdel(&duration);
		}
		ft_strdel(&ext);
	}
	free(files);
	ft_playlist_boucle(&list);
	return (list);
}
