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

t_path	*path_bot(t_room *start, t_room *room, t_path *path)
{
	t_path *tmp;

	tmp = dup_path(path);
	add_path(&tmp, room->name);
	
	if (contains_dup(tmp))
	{
		(tmp) ? (free_path(&tmp)) : NULL;
		return (NULL);
	}
	if (room->type == 2)
	{
		ft_putstr("Found end : ");
		print_path(tmp);
		return (tmp);
	}
	while (room->links)
	{
		if (!(link_contains(tmp, room->links->link)))
			path_bot(start, find_room(start, room->links->link), tmp);
		room->links = room->links->next;
	}
	return (NULL);
}