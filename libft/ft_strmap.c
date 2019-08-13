/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:21:49 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 17:21:50 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*result;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(result = ft_strnew(i)))
		return (NULL);
	result[i] = '\0';
	i = 0;
	while (s[i])
	{
		result[i] = f(s[i]);
		i++;
	}
	return (result);
}
