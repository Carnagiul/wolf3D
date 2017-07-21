/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:11:51 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/21 10:19:38 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <pthread.h>
# include <math.h>
# include <sys/time.h>

typedef struct				s_color_mlx
{
	int						red;
	int						green;
	int						blue;
}							t_color_mlx;

typedef struct				s_fractol
{
	struct s_win			*win;
	struct s_img			*img;
	int						iteration_max;
	double					zoom;
	double					move_x;
	double					move_y;
	double					zoom_i;
	double					zoom_r;
	int						alive;
	int						space;
	int						fractal;
	struct s_color_mlx		color_bg;
	struct s_color_mlx		color_pt;
	struct s_complex		z;
	int						menu;
	int						id;
}							t_fractol;

typedef struct				s_vector
{
	double					x;
	double					y;
	double					z;
}							t_vector;

typedef struct				s_texture
{
	struct s_img			*img;
	char					*name;
}							t_texture;

typedef struct				s_map
{
	char					*gnl;
	char					*get;
	int						fd;
	char					**map;
	char					**nb;
	int						**world;
	int						height;
	int						width;
}							t_map;

typedef struct				s_player
{
	int						move_up;
	int						move_down;
	int						move_left;
	int						move_right;
	int						life;
	double					move_speed;
	double					rotate_speed;
	int						in_menu_map;
	int						in_menu_map_close;
	int						in_config;
	int						in_chat;
	int						can_open;
	char					*message;
	char					*playername;
	int						in_inventory;
	int						is_god;
}							t_player;

typedef struct				s_life_img
{
	int						min;
	int						max;
	struct s_img			*img;
}							t_life_img;

typedef struct				s_coucou
{
	struct s_entity_type	*entity_type;
	struct s_entity			*entity;
	struct s_sprites		*sprite_list;
	struct s_win			*win;
	struct s_vector			pos;
	struct s_vector			dir;
	struct s_vector			plan;
	struct s_texture		***texture;
	int						texturepack;
	int						passage;
	struct s_img			*img;
	struct s_img			*settings;
	struct s_img			*xmap;
	struct s_img			*chat;
	struct s_img			*texture2;
	struct s_img			*texture3;
	struct s_map			map;
	struct s_player			p;
	int						d;
	int						noclip;
	struct s_item			**list_items;
	struct s_inventory		*inventory;
	t_playlist				*playlist;
	struct s_life_img		**life;
	int						menu_start;
	int						play_sound;
	double					*wall_dist;
}							t_coucou;

typedef struct				s_item
{
	int						id;
	int						type_id;
	int						amount_ammo;
	int						max_ammo;
	char					*name;
	char					*texture_name;
	struct s_texture		*texture;
	int						size_actual;
	int						max_stack_size;
	struct s_sound			*get_sound;
	struct s_sound			*drop_sound;
	struct s_sound			*use_sound;
	int						max_item_array;
}							t_item;

typedef struct				s_inventory
{
	struct s_item			*slot1;
	struct s_item			*slot2;
	struct s_item			*slot3;
	struct s_item			*slot4;
	struct s_item			*slot5;
	int						actual_slot;
}							t_inventory;

typedef struct				s_core
{
	struct s_coucou			*coucou;
	int						min;
	int						max;
}							t_core;

typedef struct				s_core_entity
{
	struct s_coucou			*coucou;
	int						min;
	int						max;
	struct s_entity			*e;
	struct s_entity_type	*t;
}							t_core_entity;

typedef struct				s_ray
{
	struct s_vector			pos;
	struct s_vector			dir;
	struct s_vector			plan;
	struct s_vector			raypos;
	struct s_vector			raydir;
	struct s_vector			sidedist;
	struct s_vector			deltadist;
	struct s_point			map;
	struct s_point			step;
	double					camera;
	int						lineheight;
	double					perpwalldist;
	int						h;
	int						start;
	int						end;
	int						hit;
	int						side;
}							t_ray;

typedef struct				s_mlx_line
{
	struct s_point			min;
	struct s_point			max;
	struct s_color_mlx		color;
}							t_mlx_line;

void						ft_wolf_init(int argc, char **argv);
void						ft_wolf_hooks_move_left(t_coucou *coucou);
void						ft_wolf_hooks_move_right(t_coucou *coucou);
void						ft_wolf_hooks_move_down(t_coucou *coucou);
void						ft_wolf_hooks_move_up(t_coucou *coucou);
int							red_cross(t_coucou *coucou);
void						ft_wolf_hooks_exit(t_coucou *coucou);
int							hooker2(t_coucou *coucou);
int							hooker(int k, t_coucou *coucou);
int							hooker_release(int k, t_coucou *coucou);
int							mouse_click(int keycode, int x, int y,
			t_coucou *coucou);
void						update_texture(t_coucou *coucou);
int							red_cross(struct s_coucou *coucou);
int							player_is_in_menu(t_coucou *coucou);
void						calc(t_core *core);
void						calc2(t_coucou *coucou);
void						calc_menu(t_coucou *coucou);
void						ft_menu_chat(t_coucou *coucou);
void						update_texture(t_coucou *coucou);
t_ray						set_ray_side(t_ray ray);
t_ray						init_ray(t_coucou *coucou, int x);
t_vector					create_vector(double x, double y);
t_vector					create_vector3d(double x, double y, double z);
double						ft_dpower(double n, size_t power);
void						ft_open_menu_config(t_coucou *coucou);
void						ft_menu_inv(t_coucou *coucou);
void						ft_wolf_display_texture_ground(int y, int min, int max,
			t_coucou *coucou);
void						ft_wolf_display_texture_stonebrick(int y, t_point pt,
		t_coucou *coucou, t_ray ray);
void						ft_wolf_display_texture_woodenplanks(int y, t_point pt,
		t_coucou *coucou, t_ray ray);
void						verline(int y, int min, int max, t_color_mlx color,
		t_coucou *coucou);
unsigned int				get_fps(void);
void						ft_mlx_put_pixel_img(int x, int y, t_color_mlx color,
		struct s_img *img);
void						ft_mlx_draw_linept(t_point pt1, t_point pt2,
		struct s_img *img, t_color_mlx color);
t_point						ft_create_point(int x, int y);
void						ft_wolf_display_texture(t_point pts[2], t_ray ray,
		struct s_img *img, struct s_img *texture);
t_texture					***texturepack(struct s_win *win);
t_map						ft_gen_world(char *name);
void						ft_wolf_destroy_block(t_coucou *coucou, int id,
		int dist);
void						ft_wolf_tp(t_coucou *coucou, int x, int y);
void						ft_cheat_tp(t_coucou *coucou);
void						ft_cheat_destroy(t_coucou *coucou);
int							verify_map(t_map *map);
t_item						*get_item_id(int id, char *data_line,
		struct s_win *win);
int							count_item_list(char **list);
int							is_valid_item(char **split);
void						load_itemlist(char **split, t_item **items,
		struct s_win *win);
void						print_list_items(t_item **item_list, int count);
t_item						**get_list_item(struct s_win *win);

t_inventory					*ft_wolf_inventory_init(void);
void						ft_wolf_item_clear(t_item *item, struct s_win *win);
void						ft_wolf_clear_inventory(t_inventory *inv,
		struct s_win *win);
void						ft_wolf_inventory_set_item(t_inventory *inv,
		t_item *item, struct s_win *win);
void						ft_wolf_give(t_coucou *coucou, int id);
void						print_item(t_item *item);
t_inventory					*ft_wolf_inventory_init(void);
void						ft_wolf_clear_inventory(t_inventory *inv,
		struct s_win *win);
void						ft_cheat_music(t_coucou *coucou);
t_life_img					**ft_wolf_life_img_init(struct s_win *win);
void						ft_cheat_give(t_coucou *coucou);
void						ft_cheat_damage(t_coucou *coucou);
void						ft_cheat_heal(t_coucou *coucou);
void						ft_cheat_kill(t_coucou *coucou);
void						ft_cheat_close(t_coucou *coucou);
void						ft_cheat_exit(t_coucou *coucou);
void						ft_cheat_rename(t_coucou *coucou);
void						ft_cheat_clear(t_coucou *coucou);
void						ft_cheat_god(t_coucou *coucou);
void						ft_cheat_play(t_coucou *coucou);
void						ft_cheat_stop(t_coucou *coucou);
void						ft_cheat_spawnentity(t_coucou *coucou);
void						ft_wolf_item_usage(t_coucou *coucou);

#endif
