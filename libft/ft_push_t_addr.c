/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_t_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:24:25 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/05 17:11:45 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_addr		*ft_push_t_addr(t_addr *head, void *addr, int *added)
{
	t_addr	*curr;

	curr = head;
	*added = 1;
	if (!head)
		return (ft_new_t_addr(addr));
	else
	{
		while (curr->next)
		{
			if (curr->addr == addr)
				return (head);
			curr = curr->next;
		}
		if (curr->addr != addr)
		{
			if (!(curr->next = ft_new_t_addr(addr)))
				return (NULL);
		}
		else
			*added = 0;
	}
	return (head);
}
