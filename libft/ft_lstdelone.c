/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:22:45 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/05/22 17:22:46 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdelone(t_list **link, void (*del)(void *, size_t))
{
	if (link)
	{
		del((*link)->content, (*link)->content_size);
		free(*link);
		*link = NULL;
	}
}
