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
# define DUP_NAME {ft_putendl("Error: Duplicate names."); exit(1);}
# define DUP_LINK {ft_putendl("Error: Duplicate links."); exit(1);}

/*
**	x and y position of room for visualiser and checking overlapping rooms.
*/

typedef struct		s_co_ord
{
	int				x;
	int				y;
}					t_co_ord;

typedef struct		s_links
{
	char			*link;
	struct s_links	*next;
}					t_links;

typedef struct		s_room
{
	char			*name;
	t_co_ord		pos;
	t_links			*links;
	int				type;
	struct s_room	*next;
}					t_room;

void				validate(char *s, char **map, int mode, t_room **room);
void				val_ants(char *s, char **map, t_room **room);
t_room				*val_room(char *s, char **map, int type, t_room **room);
void				val_link(char *s, char **map, t_room **room);
int					populate_map(char **file, char **map, t_room **room);
//void				link_check(char **link);

/*
** Debug
*/
void				intro(void);
void				disp_rooms(t_room *rooms);
void				disp_map(char **map);


/*
** Room handling
*/
t_room				*new_room(char *name, int xpos, int ypos, int type);
t_room				*add_room(t_room **room, char *name, int xpos, int ypos, int type);

int					map_count(void);

//				set_ants();
//				create_room();
//				set_link();

void				lemerror(void);

#endif
