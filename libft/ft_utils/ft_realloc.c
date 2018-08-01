#include <libft.h>

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char *)malloc(1)))
			return (NULL);
		free(ptr);
		return (newptr);
	}
	if (!(newptr = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		memcpy(newptr, ptr, size);
		free(ptr);
	}
	return (newptr);
}
