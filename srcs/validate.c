/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:40:52 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/02 12:17:02 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lemerror(void)
{
	ft_putendl_fd("\033[0;31mERROR", 2);
	exit(-1);
}

static int		space_jam(char *s)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == ' ')
			n++;
		i++;
	}
	return (n);
}

static void		val_cmd(char *s, char **map,  int *start, int *end, t_room **room)
{
	char	*next;

	if (ft_strcmp(s, "##start") == 0)
	{
		if (*start)
			lemerror();
		get_next_line(0, &next);
		space_jam(next) == 2 ? val_room(next, map, 1, room) : lemerror();	
		//set room to start room
		*start = 1;
		//free(next);
	}
	if (ft_strcmp(s, "##end") == 0)
	{
		if (*end)
			lemerror();
		get_next_line(0, &next);
		space_jam(next) == 2 ? val_room(next, map, 2, room) : lemerror();
		//set room to end
		*end = 1;
		//free(next);
	}
}

static void		val_m1(char *s, int *roomy, char **map, t_room **room)
{
	if (space_jam(s) == 2 && *roomy == 0)
			val_room(s, map, 0, room);
	else if (space_jam(s) == 0)
	{
		if (*roomy == 0)
			validate(NULL, NULL, 0, room);
		*roomy = 1;
		val_link(s, map, room);
	}
	else
		lemerror();
}

void			validate(char *s, char **map, int mode, t_room **room)
{
	static int	start;
	static int	end;
	static int	roomy;

	if (s == NULL)
	{
		if (!start)
			lemerror();
		if (!end)
			lemerror();
		//NEED TO CHECK THAT START AND END CONNECTED
	}
	else if (mode == 0)
		val_ants(s, map, room);
	else if (ft_strncmp("#", s, 1) == 0)
	{
		map[map_count()] = ft_strdup(s);
		if (ft_strncmp("#", s + 1, 1) == 0)
			val_cmd(s, map, &start, &end, room);
	}
	else if (ft_strncmp("L", s, 1) == 0)
		lemerror();
	else if (mode == 1)
		val_m1(s, &roomy, map, room);
}

int			populate_map(char **file, char **map, t_room **room)
{
	get_next_line(0, file);
	free(*file);
	validate(*file, map, 0, room);
	while (get_next_line(0, file))
	{
		validate(*file, map, 1, room);
		(*file) ? free(*file) : NULL;
	}
	validate(NULL, NULL, 42, room);
	return (1);
}
