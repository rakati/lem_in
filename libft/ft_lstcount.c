/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:25:39 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 21:54:08 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstcount(t_list *head)
{
	t_list	*current;
	int		c;

	current = head;
	c = 0;
	while (current->next)
	{
		current = current->next;
		c++;
	}
	return (c);
}
