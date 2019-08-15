/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:30:24 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/15 13:09:48 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		map_count(void)
{
	static int	i;

	i++;
	return (i);
}

void	val_ants(char *s, char **map, t_room **room)
{
	char	*ants;

	if (ft_atoi(s) < 0)
		lemerror();
	ants = ft_itoa(ft_atoi(s));
	if (ft_strcmp(ants, s) != 0)
		lemerror();
	//ASSIGN NUMBER OF ANTS
	map[0] = ft_strdup(s);
	ft_strdel(&ants);
}

t_room	*val_room(char *s, char **map, int type, t_room **room)
{
	char	**info;
	char	*pos[2];

	info = ft_strsplit(s, ' ');
	pos[0] = ft_itoa(ft_atoi(info[1]));
	if (ft_strcmp(pos[0], info[1]) != 0)
		lemerror();
	pos[1] = ft_itoa(ft_atoi(info[2]));
	if (ft_strcmp(pos[1], info[2]) != 0)
		lemerror();
	map[map_count()] = ft_strdup(s);
	ft_strdel(&pos[0]);
	ft_strdel(&pos[1]);
	add_room(room, info[0], ft_atoi(info[1]), ft_atoi(info[2]), type);
	free(info[0]);
	free(info[1]);
	free(info[2]);
	free(info);
	return (*room);
}

void	link_check(char **link, t_room **room)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = *room;
	ft_strequ(link[0], link[1]) ? (MISLINK) : NULL;
	while (tmp->next)
	{
		i = ft_strequ(link[0], tmp->name) ? i + 1 : i;
		i = ft_strequ(link[1], tmp->name) ? i + 1 : i;
		tmp = tmp->next;
	}
	i = ft_strequ(link[0], tmp->name) ? i + 1 : i;
	i = ft_strequ(link[1], tmp->name) ? i + 1 : i;
	i != 2 ? (MISLINK) : NULL;
}

void	val_link(char *s, char **map, t_room **room)
{
	char	**pair;
	int		n;

	n = 0;
	pair = ft_strsplit(s, '-');
	while (pair[n] != NULL)
		n++;
	if (n != 2)
		lemerror();
	link_check(pair, room);
	add_link(room, pair[0], pair[1]);
	add_link(room, pair[1], pair[0]);
	map[map_count()] = ft_strdup(s);
	free(pair[0]);
	free(pair[1]);
	free(pair);
}
