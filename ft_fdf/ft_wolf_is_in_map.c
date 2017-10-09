#include "../libft.h"

int			calc_if_ray_is_in_map(t_ray ray, t_coucou *coucou)
{
	if (ray.map.x >= coucou->map.height || ray.map.y >= coucou->map.width
			|| ray.map.x < 0 || ray.map.y < 0)
		return (1);
	return (0);
}
