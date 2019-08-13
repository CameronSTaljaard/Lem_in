/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:13:26 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 17:13:27 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordcount(char *str, char delim)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (str[i] && str[i] == delim)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != delim)
			i++;
		result++;
		while (str[i] == delim)
			i++;
	}
	return (result);
}
