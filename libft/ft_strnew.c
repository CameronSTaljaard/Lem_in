/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:13:12 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 17:13:13 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*result;

	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(result, (int)'\0', size + 1);
	return (result);
}
