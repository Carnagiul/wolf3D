#include <libft.h>

t_doom_player			*ft_doom_create_player(char *name)
{
	t_doom_player		*player;

	player = ft_malloc(sizeof(*player));
	player->pos = ft_malloc(sizeof(t_vertex_3d));
	player->speed = ft_malloc(sizeof(t_vertex_3d));
	player->name = ft_strdup(name);
	if (DOOM_DEBUG_PLAYER == 1)
		ft_printf("@B[INFO]@@: A new user have been created with name %s and pointer is %p\n", name, &player);
	return (player);
}
