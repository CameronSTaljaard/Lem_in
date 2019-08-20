/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:51:39 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/20 11:53:51 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <libft.h>
# include <get_next_line.h>

# define POOR_FORM {ft_putendl("Error : Map input poorly formatted."); exit(1);}
# define MULTI_START {ft_putendl("Error : One start room allowed."); exit(1);}
# define MULTI_END {ft_putendl("Error : One end room allowed."); exit(1);}
# define NO_START {ft_putendl("Error : Start room required."); exit(1);}
# define NO_END {ft_putendl("Error : End room required."); exit(1);}
# define NO_PATHS {ft_putendl("Error : No path to end."); exit(1);}
# define NO_ANTS {ft_putendl("Error : No value for ants."); exit(1);}
# define BAD_ANTS {ft_putendl("Error: Ants must be an integer > 0."); exit(1);}
# define BAD_X {ft_putendl("Error : Invalid value for x-coordinate."); exit(1);}
# define BAD_Y {ft_putendl("Error : Invalid value for y-coordinate."); exit(1);}

# define MAL_ERROR {ft_putendl("Error : Failed to malloc."); exit(1);}
# define DUP_NAME {ft_putendl("Error: Duplicate room names."); exit(1);}
# define POS_CLASH {ft_putendl("Error : Overlapping rooms."); exit(1);}
# define DUP_LINK {ft_putendl("Error: Duplicate links."); exit(1);}
# define MISLINK {ft_putendl("Error: Invalid room link."); exit(1);}

# define PATHS_MAX 255
# define MAP_MAX 100000
# define END 2
/*
**	x and y position of room for visualiser and checking overlapping rooms.
*/

typedef struct		s_path
{
	char			*room_name;
	struct s_path	*next_room;
}					t_path;


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
	int				ant_count;
	struct s_room	*next;
}					t_room;

typedef struct		s_staend
{
	int				start;
	int				end;
}					t_staend;

/*
** Validation
*/
void				validate(char *s, char **map, int mode, t_room **room);
void				val_ants(char *s, char **map, t_room **room);
t_room				*val_room(char *s, char **map, int type, t_room **room);
void				val_link(char *s, char **map, t_room **room);
int					populate_map(char **file, char **map, t_room **room);
void				link_check(char **link, t_room **room);
int 				contains_dup(t_path *start);

/*
** Debug
*/
void				intro(void);
void				disp_rooms(t_room *rooms);
void				disp_map(char **map);
void				print_path(t_path *path);

/*
** List handling
*/
t_room				*new_room(char *name, int xpos, int ypos, int type);
t_room				*add_room(t_room **room, char *name, int xpos, int ypos, int type);
void				free_rooms(t_room **room);
t_links				*new_link(char *name);
void				add_link(t_room **room, char *name1, char *name2);
void				free_links(t_links **link);
t_path				*new_path(char *room_name);
t_path				*add_path(t_path **path, char *room_name);
void				free_paths(t_path **path);

/*
** Room Navigation
*/
t_room				*find_room(t_room *room, char *name);
void				path_bot(t_room *start, t_room *room, t_path *path, t_path **paths);
t_path				*dup_path(t_path *path);
size_t				path_length(t_path *path);
void				sort_paths(t_path **path, int size);

/*
** Misc
*/
int					map_count(void);
size_t				array_length(t_path **path);
t_room				*find_start(t_room **rooms);

#endif
