/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frequency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:26:42 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/30 13:26:46 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_frequency(char *str, char c)
{
	size_t	i;
	size_t	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i++])
		if (str[i] == c)
			count++;
	return (count);
}
