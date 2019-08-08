/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_t_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:19:49 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/07/28 16:22:36 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str		*ft_find_t_str(t_str *head, char *s)
{
	t_str	*curr;

	curr = head;
	while (curr && ft_strcmp(curr->str, s) != 0)
		curr = curr->next;
	return (curr);
}
