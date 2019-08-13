/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:15:23 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 17:15:24 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	char	*result;
	int		length;

	if (n == MIN_INT)
		return (ft_strdup("-2147483648"));
	if (!(result = ft_strnew(ft_intlen(n))))
		return (NULL);
	length = ft_intlen(n);
	result[length] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (n)
	{
		result[length - 1] = 48 + (n % 10);
		n = n / 10;
		length--;
	}
	return (result);
}
