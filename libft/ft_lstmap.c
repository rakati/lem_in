/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:02:04 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 19:13:57 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	fresh = ft_lstnew(f(lst)->content, f(lst)->content_size);
	current = fresh;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		current = current->next;
		lst = lst->next;
	}
	return (fresh);
}
