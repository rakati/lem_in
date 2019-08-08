/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_t_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:44:34 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/07/30 12:46:30 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_t_str(t_str *head)
{
	t_str	*curr;

	curr = head;
	while (curr)
	{
		ft_putstr(curr->str);
		ft_putchar(' ');
		curr = curr->next;
	}
}
