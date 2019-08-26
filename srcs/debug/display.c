/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:01:33 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/26 13:17:04 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		disp_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("\n");
}

void		disp_links(t_links *link)
{
	ft_putstr_col_fd(CYAN, link->link, 1);
	ft_putchar(' ');
	(link->next) ? (ft_putstr("and ")) : NULL;
	if (link->next)
		disp_links(link->next);
}

void		disp_rooms(t_room *rooms)
{
	while (rooms)
	{
		ft_putstr_col_fd(GREEN, "Room: ", 1);
		ft_putendl_col_fd(GREEN, rooms->name, 1);
		ft_putstr("Location: ");
		ft_putnbr_col_fd(CYAN, rooms->pos.x, 1);
		ft_putchar(' ');
		ft_putnbr_col_fd(CYAN, rooms->pos.y, 1);
		ft_putendl("");
		ft_putstr("Number of Ants: ");
		ft_putnbr_col_fd(CYAN, rooms->ant_count, 1);
		ft_putendl("");
		ft_putstr("Links:");
		ft_putchar(' ');
		disp_links(rooms->links);
		ft_putendl("");
		ft_putendl("");
		rooms = rooms->next;
	}
}

static void	insfn(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->ant_num);
	ft_putchar('-');
	ant->path = ant->path->next_room;
	ant->curr_room = ant->path->room_name;
}

void		disp_ants(t_ant *ant, t_room **rooms)
{
	t_room	*tmp;

	tmp = *rooms;
	while (tmp && tmp->type != 2)
		tmp = tmp->next;
	if (!ft_strequ(ant->curr_room, tmp->name))
	{
		tmp = *rooms;
		while (!ft_strequ(tmp->name, ant->path->next_room->room_name))
			tmp = tmp->next;
		if (tmp->ant_count == 0 || tmp->type == 2)
		{
			tmp = *rooms;
			while (!ft_strequ(tmp->name, ant->curr_room))
				tmp = tmp->next;
			tmp->ant_count -= 1;
			insfn(ant);
			tmp = *rooms;
			while (!ft_strequ(tmp->name, ant->curr_room))
				tmp = tmp->next;
			tmp->ant_count += 1;
			ft_putstr(ant->curr_room);
		}
	}
}
