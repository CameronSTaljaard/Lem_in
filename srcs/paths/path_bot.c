/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:41:48 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/08/27 16:44:40 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		link_contains(t_path *path, char *name)
{
	while (path)
	{
		if (ft_strequ(path->room_name, name))
			return (1);
		path = path->next_room;
	}
	return (0);
}

void	path_bot(t_room *start, t_room *room, t_path *path, t_path **paths)
{
	t_path	*tmp;
	size_t	index;
	t_links	*tmp_link;

	index = 0;
	tmp_link = room->links;
	tmp = dup_path(path);
	add_path(&tmp, room->name);
	if (paths[PATHS_MAX - 1])
	{
		free_paths(&tmp);
		return ;
	}
	if (contains_dup(tmp))
	{
		free_paths(&tmp);
		return ;
	}
	if (room->type == END)
	{
		while (paths[index] && index < PATHS_MAX)
			index++;
		if (index >= PATHS_MAX)
			free_paths(&tmp);
		paths[index] = tmp;
		return ;
	}
	while (tmp_link)
	{
		path_bot(start, find_room(start, tmp_link->link), tmp, paths);
		tmp_link = tmp_link->next;
	}
	free_paths(&tmp);
}
