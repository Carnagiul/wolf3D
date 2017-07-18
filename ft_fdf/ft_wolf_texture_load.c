/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_texture_load.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:25:03 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/18 04:00:20 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			ft_wolf_display_texture(t_point pts[2], t_ray ray, t_img *img,
		t_img *texture)
{
	int			tab[5];
	double		tab2[3];

	tab[0] = pts[1].x - pts[0].x;
	tab2[1] = (double)texture->height / tab[0];
	tab2[0] = 0;
	tab2[2] = (ray.side == 0) ? ray.raypos.y + ray.perpwalldist * ray.raydir.y :
		ray.raypos.x + ray.perpwalldist * ray.raydir.x;
	tab2[2] -= floor(tab2[2]);
	tab[1] = (int)(tab2[2] * (double)texture->width);
	if ((ray.side == 0 && ray.raydir.x > 0) ||
			(ray.side == 1 && ray.raydir.y < 0))
		tab[1] = texture->width - tab[1] - 1;
	while (pts[0].x < pts[1].x)
	{
		tab[2] = (int)tab2[0] * texture->size_line;
		tab[3] = tab[2] + (tab[1] * 4);
		tab2[0] += tab2[1];
		tab[4] = (pts[0].y * 4) + (pts[0].x * img->size_line);
		img->img[tab[4]] = texture->img[tab[3]];
		img->img[++tab[4]] = texture->img[++tab[3]];
		img->img[++tab[4]] = texture->img[++tab[3]];
		pts[0].x++;
	}
}

t_texture		*get_texturepack(char *path2, char *file, t_win *win)
{
	t_texture	*texture;
	char		*name;

	name = ft_strjoin(path2, "/");
	name = ft_free_join1(name, file);
	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
		exit(0);
	texture->name = file;
	texture->img = ft_mlx_extended_gen_imgxpm(win, name);
	free(file);
	free(name);
	return (texture);
}

t_texture		**load_texture_db(t_win *win, char *path2, t_file *content)
{
	t_texture	**texture;
	int			j;

	texture = (t_texture **)malloc(sizeof(t_texture *) *
			ft_files_count_files_wa(path2));
	if (!texture)
		exit(0);
	j = 0;
	while (j < ft_files_count_files_wa(path2))
	{
		texture[j] = get_texturepack(path2, content[j].name, win);
		j++;
	}
	free(content);
	return (texture);
}

t_texture		***texturepack(t_win *win)
{
	t_file		*files;
	char		*path;
	char		*path2;
	int			i;
	t_texture	***texture;

	i = 0;
	path = ft_strdup("./textures/");
	texture = (t_texture ***)malloc(sizeof(t_texture **) *
			ft_files_count_dir_wa(path));
	if (!texture)
		exit(0);
	files = ft_create_array_dir_wa("./textures/");
	while (i < ft_files_count_dir_wa(path))
	{
		path2 = ft_string_join_path(path, files[i].name);
		texture[i] = load_texture_db(win, path2,
				ft_create_array_files_wa(path2));
		free(files[i].name);
		free(path2);
		i++;
	}
	free(path);
	free(files);
	return (texture);
}

void			update_texture(t_coucou *coucou)
{
	if (ft_strcmp(coucou->texture[coucou->texturepack][0]->name, "door.xpm")
			== 0)
		coucou->texture3 = coucou->texture[coucou->texturepack][0]->img;
	else
		coucou->texture3 = coucou->texture[coucou->texturepack][1]->img;
	if (ft_strcmp(coucou->texture[coucou->texturepack][0]->name, "door.xpm")
			== 0)
		coucou->texture2 = coucou->texture[coucou->texturepack][1]->img;
	else
		coucou->texture2 = coucou->texture[coucou->texturepack][0]->img;
}
