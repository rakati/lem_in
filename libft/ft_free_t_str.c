/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:44:12 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/07/30 15:31:20 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_t_str(t_str *head)
{
	if (!head)
		return ;
	if (head->next)
		ft_free_t_str(head->next);
	free(head->str);
	free(head);
}
