/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:18:02 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/07/25 21:26:37 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findchar(char *str, char c)
{
	int	pos;

	pos = 0;
	while (str[pos])
		if (str[pos++] == c)
			return (pos - 1);
	if (str[pos] == c)
		return (pos);
	return (-1);
}
