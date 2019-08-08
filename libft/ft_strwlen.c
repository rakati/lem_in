/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 23:21:59 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/21 23:28:54 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strwlen(int *s)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s <= 0x7f)
			count++;
		else if (*s <= 0x7ff)
			count += 2;
		else if (*s <= 0x7ffff)
			count += 3;
		else if (*s <= 0x7fffff)
			count += 4;
		s++;
	}
	return (count);
}
