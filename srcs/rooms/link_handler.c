/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:01:45 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/06 11:01:56 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_links	*new_link(char *name)
{
	t_links *new;

	new = (t_links *)malloc(sizeof(t_links));
	if (!new)
		MAL_ERROR;
	new->link = ft_strdup(name);
	new->next = NULL;
	return (new);
}

void	add_link(t_room **room, char *name1, char *name2)
{
	t_room	*tmp;
	t_links	*tmp_link;

	tmp = *room;
	while (tmp && !ft_strequ(name1, tmp->name))
		tmp = tmp->next;
	if (tmp)
	{
		if (!(tmp->links))
		{
			tmp->links = new_link(name2);
			return ;
		}
		tmp_link = tmp->links;
		while (tmp_link->next)
		{
			ft_strequ(tmp_link->link, name2) ? (DUP_LINK) : NULL;
			tmp_link = tmp_link->next;
		}
		if (ft_strequ(tmp_link->link, name2))
			DUP_LINK;
		tmp_link->next = new_link(name2);
	}
}

void	free_links(t_links **link)
{
	t_links *next;

	next = *link;
	while (*link)
	{
		next = (*link)->next;
		free((*link)->link);
		free(*link);
		(*link) = next;
	}
	*link = NULL;
}
