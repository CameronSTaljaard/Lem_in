/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:12:49 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/22 15:27:40 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	march(t_ant **ants, t_room **rooms)
{
	int		turn;
	int 	i;
	t_room	*end;
	int		num;

	num = (*rooms)->ant_count;
	end = *rooms;
	turn = 1;
	while (end && end->type != 2)
		end = end->next;
	while (end->ant_count != num)
	{
		i = 0;
		ft_putnbr(turn++);
		ft_putstr(": ");
		while (ants[i])
		{
			disp_ants(ants[i++], rooms);
			if (ants[i])
				ft_putstr(" ");
		}
		ft_putendl("");
		//disp_rooms(*rooms);
	}
}

static void	colony(t_path **paths, t_room **rooms)
{
	t_ant	**ants;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!(ants = (t_ant **)malloc(sizeof(t_ant *) * (*rooms)->ant_count)))
		MAL_ERROR;
	while (paths[j])
		j++;
	while (i <= (*rooms)->ant_count)
	{
		if (!(ants[i - 1] = (t_ant *)malloc(sizeof(t_ant))))
			MAL_ERROR;
		ants[i - 1]->ant_num = i;
		ants[i - 1]->curr_room = paths[0]->room_name;
		ants[i - 1]->path = paths[(i - 1) % j];
		i++;
	}
	march(ants, rooms);
}

void		traversal(t_path **paths, t_room **rooms)
{
	t_path	*filt[PATHS_MAX + 1] = {0};
	int		i;

	i = 0;
	path_filter(paths, filt, rooms);
	colony(filt, rooms);
	ft_putendl("FILTERED PATHS:");
	while (filt[i])
		print_path(filt[i++]);
	ft_putstr("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
