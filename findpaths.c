/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpaths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:05:24 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/07 01:45:08 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Here in this file we will using max-flow dinic's algorithm
*/

void		ft_bfs(t_container *c, char *start, char *end)
{
	t_room	*room;
	t_queue	*q;
	t_addr	*curr;

	room = ft_get_value(c->hash_table, start, c->power);
	q = ft_new_queue();
	ft_enqueue(q, room);
	room->vis = 1;
	while (q->first)
	{
		room = q->first;
		ft_pop(q);
		curr = room->neighbors;
		while (curr)
		{
			if (curr->addr->vis)
			{
				curr->vis = 1;
				((t_room*)curr->addr)->level = room->level + 1;
				ft_enqueue(q, curr->addr);
			}
			curr = curr->next;
		}
	}
}

void		ft_dinic();
