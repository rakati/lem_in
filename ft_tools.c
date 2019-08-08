/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:46:40 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/05 17:15:52 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_new_t_room(char *s, int len)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (len == 0)
	{
		if (!(new->name = ft_strdup(s)))
			return (NULL);
	}
	else
	{
		if (!(new->name = ft_strndup(s, len)))
			return (NULL);
	}
	new->neighbors = NULL;
	new->vis = 0;
	new->degree = 0;
	return (new);
}

void		ft_free_t_room(t_room *head)
{
	if (head)
	{
		free(head->name);
		ft_free_t_addr(head->neighbors);
		free(head);
	}
}
