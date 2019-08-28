/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:12:49 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/28 11:06:43 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	march(t_ant **ants, t_room **rooms)
{
	int		i;
	t_room	*end;
	int		num;

	num = (*rooms)->ant_count;
	end = *rooms;
	while (end && end->type != 2)
		end = end->next;
	while (end->ant_count != num)
	{
		i = 0;
		while (i < num)
			disp_ants(ants[i++], rooms);
		ft_putendl("");
	}
}

static void	colony(t_path **paths, t_room **rooms)
{
	t_ant		**ants;
	int			i;
	int			j;
	const int	num = (*rooms)->ant_count;

	i = 1;
	j = 0;
	if (!(ants = (t_ant **)malloc(sizeof(t_ant *) * num)))
		MAL_ERROR;
	while (paths[j])
		j++;
	while (i <= num)
	{
		if (!(ants[i - 1] = (t_ant *)malloc(sizeof(t_ant))))
			MAL_ERROR;
		ants[i - 1]->ant_num = i;
		ants[i - 1]->curr_room = paths[0]->room_name;
		ants[i - 1]->path = paths[(i - 1) % j];
		i++;
	}
	march(ants, rooms);
	i = 0;
	while (i < num)
		free(ants[i++]);
	free(ants);
}

void		traversal(t_path **paths, t_room **rooms)
{
	t_path	*filt[PATHS_MAX + 1];
	int		i;

	i = 0;
	while (i < PATHS_MAX + 1)
		filt[i++] = 0;
	path_filter(paths, filt, rooms);
	colony(filt, rooms);
}
