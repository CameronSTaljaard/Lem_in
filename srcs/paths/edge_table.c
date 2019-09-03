#include <lem_in.h>

void		create_tab(t_room *room)
{
	
}

void		create_tab2(t_map *m)
{
	int		i;
	int		r_1;
	int		r_2;
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(m->links, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		validate_link(m, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((r_1 = room_index(m, l[0], 1)) >= m->q_rooms ||
			(r_2 = room_index(m, l[1], 1)) >= m->q_rooms)
		{
			free_array(l, m, 0);
			free_array(links, m, 1);
		}
		(r_2) ? (m->tab[r_1][r_2] = 1) : 0;
		(r_1) ? (m->tab[r_2][r_1] = 1) : 0;
		free_array(l, m, 0);
	}
	free_array(links, m, 0);
}

int			solution(t_map *m, int i)
{
	if (m->tab[0][m->q_rooms - 1])
	{
		m->path[++(m->p_ind)] = m->q_rooms - 1;
		return (1);
	}
	while ((i = find_door(m, m->curr_room, i)))
	{
		if (is_last_room(m, i))
			return (1);
		else if (is_in_path(m, i))
			erase_element(m, i, 0);
	}
	if ((m->curr_room = find_door(m, m->curr_room, 0)) == 0)
	{
		if (m->p_ind == 0 || m->curr_room == 0)
			return (0);
		m->curr_room = m->path[m->p_ind - 1];
		erase_element(m, m->path[m->p_ind], 1);
		if (solution(m, 0))
			return (1);
	}
	m->path[++(m->p_ind)] = m->curr_room;
	if (solution(m, 0))
		return (1);
	return (0);
}