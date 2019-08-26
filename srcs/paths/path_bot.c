#include <lem_in.h>

// Might be pointless.
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
	if (index >= PATHS_MAX)
		return ;
	if (contains_dup(tmp))
	{
		(tmp) ? (free_paths(&tmp)) : NULL;
		return ;
	}
	if (room->type == END)
	{
		while (paths[index] && index < PATHS_MAX)
			index++;
		paths[index] = tmp;
		return ;
	}
	while (tmp_link)
	{
		path_bot(start, find_room(start, tmp_link->link), tmp, paths);
		tmp_link = tmp_link->next;
	}
}
