#include <lem_in.h>
#include <libft.h>

t_room	*find_room(t_room *room, char *name)
{
	while (room)
	{
		if (ft_strequ(room->name, name))
			return (room);
		room = room->next;
	}
	return (room);
}