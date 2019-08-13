/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:51:39 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/01 14:27:43 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <libft.h>
# include <get_next_line.h>

# define MAL_ERROR {ft_putendl("Error : Failed to malloc."); exit(1);}

/*
**	x and y position of room for visualiser and checking overlapping rooms.
*/

typedef struct		s_co_ord
{
	int				x;
	int				y;
}					t_co_ord;

/*
**	list of room names linked to a single room.
*/

typedef struct		s_links
{
	char			*link;
	struct s_links	*more;
}					t_links;

/*
**	data for each room: name, position and links.
**	type 0/1/2 for normal/start/end.
*/

typedef struct		s_room
{
	char			*name;
	t_co_ord		pos;
	t_links			*links;
	int				type;
	struct s_room	*next;
}					t_room;

void				validate(char *s, char **map, int mode);
void				val_ants(char *s, char **map);
void				val_room(char *s, char **map, int type);
void				val_link(char *s, char **map);
int					populate_map(char **file, char **map);
//void				link_check(char **link);

int					map_count(void);

//				set_ants();
//				create_room();
//				set_link();

void				lemerror(void);

#endif
