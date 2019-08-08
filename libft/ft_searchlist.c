/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:17:16 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 21:51:04 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*searchlist(t_list *src, void *content)
{
	t_list *current;

	current = src;
	while (current)
	{
		if (current->content == content)
			return (current);
		current = current->next;
	}
	return (0);
}
