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
	char			*map[100000];
	t_room			*rooms;
	t_path			*path;

	path = NULL;
	//intro();
	file = NULL;
	populate_map(&file, map, &rooms);
	//disp_map(map);
	//disp_rooms(rooms);
	rooms->ant_count = ft_atoi(map[0]);
	//For finding a room from a t_link.
	path_bot(rooms, rooms, path);
	
	//algorithm to print moves
	return (0);
}