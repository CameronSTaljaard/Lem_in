/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:05:33 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/02 12:07:18 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			main(void)
{
	char			*file;
	char			*map[MAP_MAX];
	t_room			*rooms;
	t_path			*path;
	t_path			*paths[PATHS_MAX] = {0};
	size_t			i;

	i = 0;
	path = NULL;
	file = NULL;
	populate_map(&file, map, &rooms);
	rooms->ant_count = ft_atoi(map[0]);
	path_bot(rooms, rooms, path, paths);

	// Function to make sure exit is never the first room.
	// This function is untested.
	if (rooms->type == 2)
		swap_rooms(&rooms);
	if (!paths[i])
		NO_PATHS;
	sort_paths(paths, array_length(paths));
	i = 0;
	while (paths[i])
		print_path(paths[i++]);
	while (paths[i])
		free_paths(&paths[i]);
	free_rooms(&rooms);
	//algorithm to print moves
	return (0);
}