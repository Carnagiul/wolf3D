#include <libft.h>

void		ft_doom_rename_player(char *name, t_doom_player *player)
{
	ft_strdel(&player->name);
	player->name = ft_strdup(name);
	if (DOOM_DEBUG_PLAYER == 1)
		ft_printf("@B[INFO]@@ : vous venez de changer votre nom en %s\n", player->name);
}
