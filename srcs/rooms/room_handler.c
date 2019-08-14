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
		ft_strequ(name, tmp->name) ? (DUP_NAME) : NULL;
		tmp = tmp->next;
	}
	tmp->next = new_room(name, xpos, ypos, type);
	return (*room);
}

t_links	*new_link(char *name)
{
	t_links *new;

	new = (t_links *)malloc(sizeof(t_links));
	if (!new)
		MAL_ERROR
	new->link = ft_strdup(name);
	new->next = NULL;
	return (new);
}

void	add_link(t_room **room, char *name1, char *name2)
{
	t_room	*tmp;
	t_links	*tmp_link;

	tmp = *room;
	while (tmp && !ft_strequ(name1, tmp->name))
		tmp = tmp->next;
	if (tmp)
	{
		if (!(tmp->links))
		{
			tmp->links = new_link(name2);
			return ;
		}
		tmp_link = tmp->links;
		while(tmp_link->next)
		{

			if (ft_strequ(tmp_link->link, name2))
				DUP_LINK;
			tmp_link = tmp_link->next;
		}
		if (ft_strequ(tmp_link->link, name2))
			DUP_LINK;
		tmp_link->next = new_link(name2);
	}
}