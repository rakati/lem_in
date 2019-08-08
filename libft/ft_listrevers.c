/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listrevers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:20:52 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 23:37:18 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_listrevers(t_list *list)
{
	t_list *current;

	current = list->next;
	list->next = NULL;
	while (current->next)
	{
		current->next = list;
		list = current;
		current = current->next;
	}
	current->next = list;
	return (current);
}
