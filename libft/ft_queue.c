/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 21:55:13 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/05 17:03:39 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue			*ft_new_queue(void)
{
	t_queue		*new;

	new = (t_queue*)malloc(sizeof(t_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void			ft_enque(t_queue *q, void *data)
{
	if (q->first)
	{
		q->last->next = ft_new_t_addr(data);
		q->last = q->last->next;
	}
	else
	{
		q->first = ft_new_t_addr(data);
		q->last = q->first;
	}
}

void			ft_pop(t_queue *q)
{
	t_addr		*temp;

	temp = q->first;
	if (q->first == q->last)
	{
		q->first = NULL;
		q->last = NULL;
	}
	else
	{
		q->first = q->first->next;
		temp->next = NULL;
	}
	ft_free_t_addr(temp);
}
