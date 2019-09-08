/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:15:20 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/09/08 18:15:21 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_queue			*queue_new(t_room *room)
{
	t_queue	*ret;

	if (!room)
		return (NULL);
	ret = (t_queue *)malloc(sizeof(t_list));
	ret->room = room;
	ret->next = NULL;
	return (ret);
}

void			queue_add(t_queue *queue, t_room *room)
{
	if (!queue)
	{
		queue = queue_new(room);
		return ;
	}
	while (queue->next)
	{
		if (queue->room == room)
			return ;
		queue = queue->next;
	}
	queue->next = queue_new(room);
}

void			queue_remove(t_queue **queue)
{
	t_queue *tmp;

	if (!queue)
		return ;
	tmp = (*queue)->next;
	free(*queue);
	*queue = tmp;
}
