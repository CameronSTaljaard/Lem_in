/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_filter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 09:57:55 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/26 13:36:08 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	mark_rooms(t_path *path, t_room **rooms)
{
	t_room	*tmp;

	while (path)
	{
		tmp = *rooms;
		while (!ft_strequ(tmp->name, path->room_name))
			tmp = tmp->next;
		if (!tmp->type)
			tmp->x_path = 1;
		path = path->next_room;
	}
}

static int	end_links(t_room *rooms)
{
	int		lnum;
	t_room	*end;
	t_links	*elinks;

	lnum = 0;
	end = rooms;
	while (end && end->type != 2)
		end = end->next;
	elinks = end->links;
	while (elinks)
	{
		lnum++;
		elinks = elinks->next;
	}
	return (lnum);
}

static int	no_cross(t_path *path, t_room *rooms)
{
	t_room	*tmp;

	while (path)
	{
		tmp = rooms;
		while (!ft_strequ(tmp->name, path->room_name))
			tmp = tmp->next;
		if (tmp->x_path)
			return (0);
		path = path->next_room;
	}
	return (1);
}

void		path_filter(t_path **paths, t_path **filt, t_room **rooms)
{
	int	i;
	int	j;
	int	max;

	i = 1;
	j = 1;
	max = end_links(*rooms);
	filt[0] = paths[0];
	mark_rooms(paths[0], rooms);
	while (i < max && paths[j])
	{
		if (no_cross(paths[j], *rooms))
		{
			filt[i] = paths[j];
			mark_rooms(paths[j], rooms);
			i++;
		}
		j++;
	}
}
