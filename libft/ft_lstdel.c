/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:17:48 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 17:17:49 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **link, void (*del)(void *, size_t))
{
	t_list	*next;

	while (*link)
	{
		next = (*link)->next;
		del((*link)->content, (*link)->content_size);
		free(*link);
		*link = next;
	}
	*link = NULL;
}
