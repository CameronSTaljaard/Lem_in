/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:05:33 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/26 11:06:02 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			main(void)
{
	char			*file;
	char			*map[MAP_MAX];
	t_room			*rooms;
	t_path			*path;
	t_path			*paths[PATHS_MAX + 1] = {0};
	size_t			i;

	i = 0;
	path = NULL;
	file = NULL;
	populate_map(&file, map, &rooms);
	disp_map(map);
	rooms->ant_count = ft_atoi(map[0]);
	path_bot(rooms, find_start(&rooms), path, paths);
	if (!paths[i])
		NO_PATHS;
	sort_paths(paths, array_length(paths));
	traversal(paths, &rooms);
	while (paths[i])
		free_paths(&paths[i++]);
	free_rooms(&rooms);
	return (0);
}
