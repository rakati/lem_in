/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconcate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:06:35 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 18:12:11 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstconcate(t_list *list1, t_list *list2)
{
	t_list	*current1;

	current1 = list1;
	while (current1->next)
		current1 = current1->next;
	current1->next = list2;
	return (list1);
}
