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
	bfs(find_start(&rooms));
	path = construct_path(rooms);
	disp_map(mappy);
	traversal(path, &rooms);
	free_rooms(&rooms);
	free_paths(&path);
	return (0);
}
