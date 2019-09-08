#include <lem_in.h>

void reverse(t_path **head_ref) 
{
	t_path *prev = NULL;
	t_path *current = *head_ref;
	t_path *next;
	while (current != NULL)
	{
		next  = current->next_room;
		current->next_room = prev;
		prev = current;
		current = next;
    }
	*head_ref = prev;
}

t_path	*construct_path(t_room *start)
{
	t_room	*curr;
	t_room	*end;
	t_links	*tmp_link;
	t_path	*path;
	int		dist;

	end = start;
	while (end->type != END)
		end = end->next;
	curr = end;
	dist = end->dist;
	path = NULL;
	add_path(&path, end->name);
	while(curr->dist != 1)
	{
		tmp_link = curr->links;
		while (tmp_link)
		{
			if (tmp_link->room->dist == curr->dist - 1)
			{
				add_path(&path, tmp_link->room->name);
				curr = tmp_link->room;
			}
			tmp_link = tmp_link->next;
		}
	}
	reverse(&path);
	return (path);
}

void	bfs(t_room *start)
{
	t_queue	*queue;
	t_links *tmp_link;
	t_room	*room;
	t_room	*end;

	end = start;
	while (end->type != END)
		end = end->next;
	room = start;
	queue = queue_new(room);
	room->dist = 1;
	while (queue && end->dist == 0)
	{
		tmp_link = queue->room->links;
		while(tmp_link)
		{
			if (tmp_link->room->dist == 0)
			{
				queue_add(queue, tmp_link->room);
				tmp_link->room->dist = queue->room->dist + 1;
			}
			tmp_link = tmp_link->next;
		}
		queue_remove(&queue);
	}
	while (queue)
		queue_remove(&queue);
}