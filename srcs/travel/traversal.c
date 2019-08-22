/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:12:49 by bmarks            #+#    #+#             */
/*   Updated: 2019/08/22 11:22:50 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	traversal(t_path **paths, t_room **rooms)
{
	t_path	*filt[PATHS_MAX + 1] = {0};
	int		i;

	i = 0;
	path_filter(paths, filt, rooms);
	ft_putendl("FILTERED PATHS:");
	while (filt[i])
		print_path(filt[i++]);
	ft_putstr("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
