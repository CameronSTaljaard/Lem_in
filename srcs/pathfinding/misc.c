#include <libft.h>
#include <lem_in.h>

void	test_path(t_path *path, int ant, int antcount)
{
	if (ant > antcount)
		return ;
	if (!path)
		return ;
	if (!path->next_room)
		return ;
	if (path->next_room)
	{
		ft_putchar('L');
		ft_putnbr(ant);
		ft_putchar('-');
		ft_putendl(path->next_room->room_name);
		path = path->next_room;
		test_path(path, ant, antcount);
	}
}

int		paths_intersect(t_path *path1, t_path *path2)
{
	t_path *temp_path1;
	t_path *temp_path2;

	temp_path1 = path1->next_room;
	temp_path2 = path2->next_room;

	while (temp_path1->next_room && temp_path2->next_room)
	{
		if (ft_strequ(temp_path1->room_name, temp_path2->room_name))
			return (0);
		temp_path1 = temp_path1->next_room;
		temp_path2 = temp_path2->next_room;
	}
	return (1);
}