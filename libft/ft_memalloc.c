/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:14:00 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 17:14:01 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void *result;

	if (size <= 0)
		return (NULL);
	result = malloc(size);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, size);
	return (result);
}
