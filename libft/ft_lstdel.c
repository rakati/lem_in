/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 21:31:45 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 21:09:01 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*swap;

	if (alst)
	{
		while (*alst)
		{
			swap = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = swap;
		}
	}
}
