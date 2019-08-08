/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:52:04 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 21:36:02 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	size_t	i;

	p = (char*)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == c)
			return ((void*)(&p[i]));
		i++;
	}
	return (0);
}
