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

static void		val_cmd(char *s, char **map,  int *start, int *end)
{
	char	*next;

	if (ft_strcmp(s, "##start") == 0)
	{
		if (*start)
			lemerror();
		if (get_next_line(0, &next) && space_jam(s) == 2)
			val_room(next, map, 1);
		else
			lemerror();	
		//set room to start room
		*start = 1;
		//free(next);
	}
	if (ft_strcmp(s, "##end") == 0)
	{
		if (*end)
			lemerror();
		if (get_next_line(0, &next) && space_jam(s) == 2)
			val_room(next, map, 2);
		else
			lemerror();	
		//set room to end
		*end = 1;
		//free(next);
	}
}

static void		val_m1(char *s, int *roomy, char **map)
{
	if (space_jam(s) == 2 && *roomy == 0)
			val_room(s, map, 0);
	else if (space_jam(s) == 0)
	{
		if (*roomy == 0)
			validate(NULL, NULL, 0);
		*roomy = 1;
		val_link(s, map);
	}
	else
		lemerror();
}

void			validate(char *s, char **map, int mode)
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
		val_ants(s, map);
	else if (ft_strncmp("#", s, 1) == 0)
	{
		map[map_count()] = ft_strdup(s);
		if (ft_strncmp("#", s + 1, 1) == 0)
			val_cmd(s, map, &start, &end);
	}
	else if (ft_strncmp("L", s, 1) == 0)
		lemerror();
	else if (mode == 1)
		val_m1(s, &roomy, map);
}

int			populate_map(char **file, char **map)
{
	get_next_line(0, file);
	free(*file);
	validate(*file, map, 0);
	while (get_next_line(0, file))
	{
		validate(*file, map, 1);
		(*file) ? free(*file) : NULL;
	}
	validate(NULL, NULL, 42);
	return (1);
}
