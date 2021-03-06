/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:45:38 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 18:45:39 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd(t_list **head, t_list *new)
{
	if (head && new)
	{
		new->next = *head;
		*head = new;
	}
}
