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

	//intro();
	file = NULL;
	populate_map(&file, map, &rooms);
	//disp_map(map);
	disp_rooms(rooms);

	//For finding a room from a t_link.
	if (find_room(rooms, "1"))
		ft_putendl_col_fd(GREEN, "A room named \"1\" exists.", 1);
	else
		ft_putendl("No room named \"1\" exists.");
	
	//algorithm to print moves
	return (0);
}