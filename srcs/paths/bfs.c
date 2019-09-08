#include <lem_in.h>

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
	//print_queue(queue);
	while (queue && end->dist == 0)
	{
		tmp_link = queue->room->links;
		while(tmp_link)
		{
			if (tmp_link->room->dist == 0)
			{
				queue_add(queue, tmp_link->room);
				tmp_link->room->dist = queue->room->dist + 1;
				//printf("%s:%d -> %s:%d\n" , queue->room->name, queue->room->dist, tmp_link->room->name, tmp_link->room->dist);
			}
			tmp_link = tmp_link->next;
		}
		queue_remove(&queue);
		//print_queue(queue);
	}
}