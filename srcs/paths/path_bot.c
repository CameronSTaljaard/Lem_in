#include <lem_in.h>

int contains_dup(t_path *start) 
{ 
    t_path *ptr1;
	t_path *ptr2;
	t_path *dup; 
    ptr1 = start; 

    while (ptr1 != NULL && ptr1->next_room != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next_room != NULL) 
        { 
            if (ft_strequ(ptr1->room_name, ptr2->next_room->room_name)) 
				return (1);
            else
                ptr2 = ptr2->next_room; 
        } 
        ptr1 = ptr1->next_room; 
    }
	return (0);
} 

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

void	print_path(t_path *path)
{
	while (path)
	{
		ft_putstr_col_fd(CYAN, path->room_name, 1);
		(path->next_room) ? ft_putstr_col_fd(CYAN, "->", 1) : NULL;
		path = path->next_room;
	}
	ft_putchar('\n');
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
	
	if (contains_dup(tmp))
	{
		(tmp) ? (free_paths(&tmp)) : NULL;
		return ;
	}
	if (room->type == END)
	{
		while(paths[index])
			index++;
		paths[index] = tmp;
		return ;
	}
	while (tmp_link)
	{
		//if (!(link_contains(tmp, tmp_link->link)))
			path_bot(start, find_room(start, tmp_link->link), tmp, paths);
		tmp_link = tmp_link->next;
	}
	return ;
}