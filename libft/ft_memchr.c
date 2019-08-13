/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:23:44 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 17:23:45 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *str, int c, size_t size)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	c2;

	if (size == 0)
		return (NULL);
	c2 = (unsigned char)c;
	i = 0;
	ptr = (unsigned char *)str;
	while (i < size)
	{
		if (ptr[i] == c2)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
