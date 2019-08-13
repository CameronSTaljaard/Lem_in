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
		//(name = tmp->name) ? (DUP_NAME) : NULL;
		tmp = tmp->next;
	}
	tmp->next = new_room(name, xpos, ypos, type);
	return (*room);
}