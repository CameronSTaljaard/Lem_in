/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:05:33 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/03 11:31:09 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			map_count(void)
{
	static int	i = -1;

	i++;
	return (i);
}

int			main(void)
{
	t_map			mappy;
	t_room			*rooms;
	t_path			*path;
	t_path			*paths[PATHS_MAX + 1];
	size_t			i;

	i = 0;
	while (i < PATHS_MAX + 1)
		paths[i++] = 0;
	i = 0;
	path = NULL;
	populate_map(&mappy, &rooms);
	room_swap(&rooms);
	set_ants(&mappy, &rooms);
	path_bot(rooms, find_start(&rooms), path, paths);
	if (!paths[i])
		NO_PATHS;
	disp_map(mappy.map);
	sort_paths(paths, array_length(paths));
	traversal(paths, &rooms);
	while (paths[i])
		free_paths(&paths[i++]);
	free_rooms(&rooms);
	return (0);
}
