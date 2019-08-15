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

void	sort_paths(t_path **path, int size)
{
	size_t	i;
	size_t	j;
	t_path	*tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (path_length(path[j]) > path_length(path[i]))
			{
				tmp = path[i];
				path[i] = path[j];
				path[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

size_t	array_length(t_path **path)
{
	size_t	i;

	i = 0;
	while (path[i])
		i++;
	return (i);
}
