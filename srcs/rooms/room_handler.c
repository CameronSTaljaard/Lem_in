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
		//(name = tmp->name) ? (DUP_NAME) : NULL;
		tmp = tmp->next;
	}
	tmp->next = new_room(name, xpos, ypos, type);
	return (*room);
}

void	new_link(t_room **room, char *name)
{
	t_room *tmp;
	t_links *new;

	new->link = ft_strdup(name);
	tmp = *room;
	if (!(*room)->links)
		(*room)->links = new;
}

void	add_link(t_room **room, char *name1, char *name2)
{
	t_room *tmp;

	tmp = *room;
	if ((*room)->name == name1)
	{
		if (!(*room)->links)
			new_link(room, name2);
		else
		{
			while (tmp->links->next)
			{
				if (tmp->links->link == name2)
					DUP_LINK;
				tmp->links = tmp->links->next;
			}
			new_link(&tmp, name2);
		}
	}
	else
	{
		while (tmp->next)
		{
			{
				if (!tmp->links)
					new_link(&tmp, name2);
				else
					while (tmp->links->next)
					{
						if (tmp->links->link == name2)
							DUP_LINK;
						tmp->links = tmp->links->next;
					}
					new_link(&tmp, name2);
			}
		}
	}
}