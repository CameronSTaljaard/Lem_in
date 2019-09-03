/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:40:52 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/27 16:38:12 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		char_jam(char *s, char brk)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == brk)
			n++;
		i++;
	}
	return (n);
}

static void		val_cmd(char *s, char **map, t_staend *se, t_room **room)
{
	char	*next;

	if (ft_strcmp(s, "##start") == 0)
	{
		if (se->start == 1)
			MULTI_START;
		get_next_line(0, &next);
		char_jam(next, ' ') == 2 ? val_room(next, map, 1, room) : (POOR_FORM);
		se->start = 1;
		free(next);
	}
	if (ft_strequ(s, "##end"))
	{
		if (se->end == 1)
			MULTI_END;
		get_next_line(0, &next);
		char_jam(next, ' ') == 2 ? val_room(next, map, 2, room) : (POOR_FORM);
		se->end = 1;
		free(next);
	}
}

static void		val_m1(char *s, int *roomy, char **map, t_room **room)
{
	if (char_jam(s, ' ') == 2 && *roomy == 0)
		val_room(s, map, 0, room);
	else if (char_jam(s, ' ') == 0 && char_jam(s, '-'))
	{
		if (*roomy == 0)
			validate(NULL, NULL, 0, room);
		*roomy = 1;
		val_link(s, map, room);
	}
	else
		POOR_FORM;
}

void			validate(char *s, char **map, int mode, t_room **room)
{
	static t_staend		se;
	static int			roomy;

	if (s == NULL)
	{
		if (!se.start)
			NO_START;
		if (!se.end)
			NO_END;
	}
	else if (mode == 0)
		val_ants(s, map, room);
	else if (ft_strncmp("#", s, 1) == 0)
	{
		map[map_count()] = ft_strdup(s);
		if (ft_strncmp("#", s + 1, 1) == 0)
			val_cmd(s, map, &se, room);
	}
	else if (ft_strncmp("L", s, 1) == 0)
	{
		POOR_FORM;
	}
	else if (mode == 1)
		val_m1(s, &roomy, map, room);
}

int				populate_map(char **map, t_room **room)
{
	char	*file;

	get_next_line(0, &file);
	validate(file, map, 0, room);
	free(file);
	while (get_next_line(0, &file))
	{
		validate(file, map, 1, room);
		(file) ? free(file) : NULL;
	}
	validate(NULL, NULL, 42, room);
	return (1);
}
