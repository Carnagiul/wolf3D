/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 05:15:47 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/20 08:27:52 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENTITY_H
# define FT_ENTITY_H

typedef struct				s_entity_type
{
	int						type_id;
	struct s_img			*img;
	char					*name;
	char					*path;
	int						max_life;
	int						damage_atk;
	int						damage_cooldown;
	struct s_sound			*damage_sound;
	struct s_sound			*death_sound;
	struct s_entity_type	*next;
}							t_entity_type;

typedef struct				s_entity
{
	int						type_id;
	int						id;
	struct s_vector			pos;
	struct s_vector			dir;
	struct s_vector			plan;
	int						is_alive;
	int						health_actual;
	int						last_atk;
	struct s_entity			*next;
}							t_entity;

void						ft_entity_add(t_entity **ents, t_entity_type **type, t_vector pos, int type_id);
t_entity					*ft_entity_create(int id, t_entity_type **type, t_vector pos);
void						ft_entity_remove(t_entity **ents, int id);
void						ft_entity_type_add(t_entity_type **type, char *filecontent);
t_entity_type				*ft_entity_type_create(char *contentfile);
t_entity_type				*ft_entity_type_init(t_win *win);
void						ft_entity_type_load(t_entity_type **type, t_win *win);
void						ft_entity_display(struct s_core *core);

#endif
