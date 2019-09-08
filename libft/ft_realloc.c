/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:34:13 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/09/08 18:34:14 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *ptr, size_t new_size)
{
	unsigned char	*new;
	unsigned char	*tmp_ptr;
	size_t			i;

	tmp_ptr = (unsigned char *)ptr;
	i = 0;
	new = (unsigned char *)malloc(new_size);
	while (i < new_size)
		new[i] = 0;
	i = 0;
	while (tmp_ptr[i] && i < new_size)
	{
		new[i] = tmp_ptr[i];
		i++;
	}
	free(ptr);
	return (new);
}
