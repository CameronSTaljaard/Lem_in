#include <libft.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	unsigned char	*new;
	unsigned char	*tmp_ptr;
	size_t	i;

	tmp_ptr = (unsigned char *)ptr;
	i = 0;
	new = (unsigned char *)malloc(new_size);
	while (i < new_size)
		new[i] = 0;
	i = 0;
	while (tmp_ptr[i] && i < new_size && i < old_size)
	{
		new[i] = tmp_ptr[i];
		i++;
	}
	free(ptr);
	return (new);
}