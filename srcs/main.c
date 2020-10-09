/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:05:33 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/09 09:51:38 by bmarks           ###   ########.fr       */
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
	char			*mappy[MAP_MAX];
	t_room			*rooms;
	t_path			*path;

	populate_map(mappy, &rooms);
	room_swap(&rooms);
	set_ants(mappy, &rooms);
<<<<<<< HEAD
<<<<<<< HEAD
	bfs(find_start(&rooms));
	path = construct_path(rooms);
	disp_map(mappy);
	traversal(path, &rooms);
	free_rooms(&rooms);
	free_paths(&path);
=======
=======
>>>>>>> parent of 901544a... Commiting BFS.
	path_bot(rooms, find_start(&rooms), path, paths);
	if (!paths[i])
		NO_PATHS;
	disp_map(mappy);
	sort_paths(paths, array_length(paths));
	traversal(paths, &rooms);
	while (paths[i])
		free_paths(&paths[i++]);
	free_rooms(&rooms);
<<<<<<< HEAD
>>>>>>> parent of 901544a... Commiting BFS.
=======
>>>>>>> parent of 901544a... Commiting BFS.
	return (0);
}
