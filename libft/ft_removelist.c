/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delelement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 22:25:02 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 23:19:13 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_removelist(t_list *item)
{
	ft_memdel(item->content);
	free((void*)item->content_size);
	item->next = NULL;
	free(item);
}

t_list			*ft_remove_item(t_list *list, t_list *item)
{
	t_list *res;

	res = list;
	if (list == item)
	{
		res = list->next;
		ft_removelist(item);
	}
	else if (!(item->next))
	{
		while (list->next != item)
			list = list->next;
		ft_removelist(item);
	}
	else
	{
		while (list->next != item)
			list = list->next;
		list->next = item->next;
		ft_removelist(item);
	}
	return (res);
}
