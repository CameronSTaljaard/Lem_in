/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:10:24 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 17:10:25 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *str, int c, size_t size)
{
	size_t			i;
	unsigned char	*pstr;

	pstr = (unsigned char *)str;
	if (size == 0)
		return (str);
	i = 0;
	while (i < size)
	{
		pstr[i] = c;
		i++;
	}
	return (str);
}
