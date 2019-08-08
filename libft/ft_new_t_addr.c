/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_t_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:19:39 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/01 17:30:58 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_addr		*ft_new_t_addr(void *addr)
{
	t_addr	*new;

	if (!(new = (t_addr*)malloc(sizeof(t_addr))))
		return (NULL);
	new->addr = addr;
	new->next = NULL;
	return (new);
}
