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
	new->links = NULL;
	new->next = NULL;
	return (new);
}

t_room	*add_room(t_room **room, char *name, int xpos, int ypos, int type)
{
	t_room *tmp;

	tmp = *room;
	if (!*room)
	{
		*room = new_room(name, xpos, ypos, type);
		return (*room);
	}
	while (tmp->next)
	{
		ft_strequ(name, tmp->name) ? (DUP_NAME) : NULL;
		if (tmp->pos.x == xpos)
			tmp->pos.y == ypos ? (POS_CLASH) : NULL;
		tmp = tmp->next;
	}
	ft_strequ(name, tmp->name) ? (DUP_NAME) : NULL;
	if (tmp->pos.x == xpos)
			tmp->pos.y == ypos ? (POS_CLASH) : NULL;
	tmp->next = new_room(name, xpos, ypos, type);
	return (*room);
}

void	free_rooms(t_room **room)
{
	t_room *next;

	while(*room)
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