/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:46:19 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 18:46:20 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_sort_array(char **str, int len)
{
	int i;
	int j;

	i = 1;
	while (i < len)
	{
		j = i;
		while (j > 0 && (ft_strcmp(str[j - 1], str[j])) > 0)
		{
			ft_strswap(&str[j - 1], &str[j]);
			j--;
		}
		i++;
	}
}
