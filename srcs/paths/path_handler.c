#include <lem_in.h>

void	free_path(t_path **path)
{
	t_path *next;

	while (*path)
	{
		next = (*path)->next_room;
		free((*path)->room_name);
		*path =  (*path)->next_room;
	}
	*path = NULL;
}

t_path	*new_path(char *room_name)
{
	t_path *new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		MAL_ERROR;
	new->room_name = ft_strdup(room_name);
	new->next_room = NULL;
	return (new);
}

t_path	*dup_path(t_path *path)
{
	t_path *new;

	if (!path)
		return (NULL);

	new = NULL;
	while (path)
	{
		add_path(&new, path->room_name);
		path = path->next_room;
	}
	return (new);
}

t_path	*add_path(t_path **path, char *room_name)
{
	t_path *tmp;

	tmp = *path;
	if (!*path)
	{
		*path = new_path(room_name);
		return (*path);
	}
	while (tmp->next_room)
		tmp = tmp->next_room;
	tmp->next_room = new_path(room_name);
	return (*path);
}