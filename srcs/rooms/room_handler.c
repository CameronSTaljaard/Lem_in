/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:45:12 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/08/27 16:51:27 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_room	*new_room(char *name, int xpos, int ypos, int type)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		MAL_ERROR;
	new->name = ft_strdup(name);
	new->pos.x = xpos;
	new->pos.y = ypos;
	new->type = type;
	new->ant_count = 0;
	new->x_path = 0;
	new->links = NULL;
	new->next = NULL;
	return (new);
}

t_room	*add_room(t_room **room, char **info, int type)
{
	t_room *tmp;

	tmp = *room;
	if (!*room)
	{
		*room = new_room(info[0], ft_atoi(info[1]), ft_atoi(info[2]), type);
		return (*room);
	}
	while (tmp->next)
	{
		ft_strequ(info[0], tmp->name) ? (DUP_NAME) : NULL;
		if (tmp->pos.x == ft_atoi(info[1]))
			tmp->pos.y == ft_atoi(info[2]) ? (POS_CLASH) : NULL;
		tmp = tmp->next;
	}
	ft_strequ(info[0], tmp->name) ? (DUP_NAME) : NULL;
	if (tmp->pos.x == ft_atoi(info[1]))
		tmp->pos.y == ft_atoi(info[2]) ? (POS_CLASH) : NULL;
	tmp->next = new_room(info[0], ft_atoi(info[1]), ft_atoi(info[2]), type);
	return (*room);
}

void	free_rooms(t_room **room)
{
	t_room *next;

	while (*room)
	{
		free_links(&((*room)->links));
		free((*room)->name);
		free(*room);
		next = (*room)->next;
		(*room) = next;
	}
	*room = NULL;
}

t_room	*find_start(t_room **rooms)
{
	t_room *tmp;

	tmp = *rooms;
	while (tmp && tmp->type != 1)
		tmp = tmp->next;
	return (tmp);
}

void	start_swap(t_room **rooms)
{
	t_room	*start;
	t_room	*tmp;

	start = *rooms;
	tmp = *rooms;
	while (start && start->type != 1)
		start = start->next;
	if (!ft_strequ(tmp->name, start->name))
	{
		while (!ft_strequ(tmp->next->name, start->name))
			tmp = tmp->next;
		tmp->next = start->next;
		start->next = *rooms;
		*rooms = start;
	}
}
