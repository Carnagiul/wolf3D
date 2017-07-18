/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_music.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 03:13:51 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/18 07:13:42 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MUSIC_H
# define FT_MUSIC_H

typedef struct			s_sound
{
	int					len;
	char				*sound;
}						t_sound;

typedef struct			s_playlist
{
	clock_t				start;
	clock_t				end;
	struct s_sound		*sound;
	struct s_playlist	*next;
}						t_playlist;

void					free_t_sound(t_sound *sound);
t_sound					*ft_sound_create(char *sound_name, char *len);
void					ft_playlist_add_sound(t_playlist **playlist,
		t_sound *sound);
t_playlist				*ft_playlist_create(t_sound *sound);
void					ft_playlist_boucle(t_playlist **playlist);
t_playlist				*ft_playlist_play(t_playlist *play);
t_playlist				*ft_playlist_load(void);
void					ft_playlist_forceplay(t_playlist **play);

#endif
