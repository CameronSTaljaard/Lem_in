/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:15:05 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 17:15:06 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	len;

	if (*needle == '\0')
		return ((char *)haystack);
	len = ft_strlen(needle);
	while (*haystack && size-- >= len)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
