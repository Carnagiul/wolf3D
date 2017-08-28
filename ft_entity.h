/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 05:15:47 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/23 23:03:46 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENTITY_H
# define FT_ENTITY_H

typedef struct					s_entity_damage
{
	int							amount;
	int							radius;
	int							scope;
	int							cooldown;
	int							last_use;
}								t_entity_damage;

typedef struct					s_entity_bonus
{
	double						health;
	int							health_radius;
	double						reload;
	int							reload_radius;
	double						speed;
	int							speed_radius;
}								t_entity_bonus;

typedef struct					s_entity_death
{
	int							death_damage;
	int							death_scope;
	int							death_radius;
	int							death_drop;
}								t_entity_deaht;

typedef struct					s_entity_global
{
	int							is_god;
	int							is_alive;
	int							is_throw;
	int							can_move;
	int							can_attack;
	int							max_health;
	int							actual_health;
}								t_entity_global;

typedef struct					s_drop
{
	struct s_item				*item;
	struct s_drop				*next;
}								t_drop;

typedef struct					s_entity_sound
{
	struct s_sound				*spawn;
	struct s_sound				*attack;
	struct s_sound				*move;
	struct s_sound				*death;
	struct s_sound				*magic;
}								t_entity_sound;

typedef struct					s_entity_interaction
{
	int							can_take;
	int							can_drag;
	int							can_craft;
	int							can_teleport;
}								t_entity_interaction;

typedef struct					s_entity_data
{
	int							type_id;
	struct s_entity_damage		*damage;
	struct s_entity_bonus		*bonus;
	struct s_entity_death		*death;
	struct s_entity_global		*data;
	struct s_drop				*drop;
	struct s_img				*img;
	struct s_entity_sound		*sound;
	struct s_vector				pos;
	struct s_entity_interact	*interaction;
	int							id;
}								t_entity_data;

typedef struct					s_entity_type
{
	int							type_id;
	struct s_img				*img;
	char						*name;
	char						*path;
	int							max_life;
	int							damage_atk;
	int							damage_cooldown;
	struct s_sound				*damage_sound;
	struct s_sound				*death_sound;
	struct s_entity_type		*next;
}								t_entity_type;

typedef struct					s_entity
{
	int							type_id;
	struct s_vector				pos;
	struct s_vector				dir;
	struct s_vector				plan;
	struct s_img				*img;
	int							is_alive;
	int							max_health;
	int							health_actual;
	int							last_atk;
	int							id;
	struct s_entity				*next;
}								t_entity;

typedef struct					s_sprites
{
	struct s_img				*img;
	struct s_vector				pos;
	struct s_sprites			*next;
	double						vmove;
}								t_sprites;

typedef struct					s_ray_sprites
{
	int							h;
	int							w;
	int							min;
	int							max;
	double						perpwalldist;
	struct s_vector				sprite;
	struct s_vector				transform;
	double						invdet;
	struct s_point				start;
	struct s_point				end;
	struct s_point				sprite_data;
	struct s_point				screen_data;
	struct s_point				texture;
}								t_ray_sprites;

typedef struct					s_raysprites
{
	struct s_vector				pos;
	struct s_vector				transform;
	double						invdet;
	double						vmove;
	struct s_point				screen;
	struct s_point				start;
	struct s_point				end;
	struct s_point				data;
}								t_raysprites;

void							ft_entity_add(t_entity **ents,
		t_entity_type **type, t_vector pos, int type_id);
t_entity						*ft_entity_create(int id,
		t_entity_type **type, t_vector pos);
void							ft_entity_remove(t_entity **ents, int id);
void							ft_entity_type_add(t_entity_type **type,
		char *filecontent);
t_entity_type					*ft_entity_type_create(char *contentfile);
t_entity_type					*ft_entity_type_init(t_win *win);
void							ft_entity_type_load(t_entity_type **type,
		t_win *win);
void							ft_entity_display(struct s_core *core);
t_sprites						*ft_wolf_create_sprite(char *xpm, t_win *win,
		double x, double y);
t_vector						ft_get_sprite_pos(t_sprites *sprites,
		t_coucou *coucou);
t_ray_sprites					ft_calc_start_end(t_ray_sprites ray,
		t_core *core);
t_ray_sprites					ft_init_ray_sprite2(t_sprites *sprites,
		t_coucou *coucou,
		t_ray_sprites ray, t_core *core);
int								ft_entity_get_texture_x(t_ray_sprites ray,
		t_sprites *sprites);
int								ft_entity_get_texture_y(t_ray_sprites ray,
		t_sprites *sprites, int y);

#endif
