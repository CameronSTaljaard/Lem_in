#include <lem_in.h>

t_room	*new_room(char *name, t_co_ord coords, int type)
{
		//CHECK IF NAME ALREADY EXISTS
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		MAL_ERROR;
	new->name = ft_strdup(name);
	new->pos = coords;
	new->type = type;
	new->next = NULL;
	return (new);
}

t_room	*add_room(t_room *room, char *name, t_co_ord coords, int type)
{
	t_room *tmp;

	tmp = room;
	if (!tmp)
	{
		if (!(tmp = new_room(name, coords, type)))
			MAL_ERROR;
		return (room);
	}
	while (tmp->next)
		tmp = room->next;
	room->next = new_room(name, coords, type);
	return (room);
}