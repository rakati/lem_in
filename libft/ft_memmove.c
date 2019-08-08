/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:00:14 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/09 13:52:57 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dest;
	unsigned char	backup[len + 1];
	const char		*srcc;
	size_t			i;

	if (len > 65535)
		return (0);
	srcc = (const char*)src;
	dest = (char*)dst;
	i = 0;
	while (i < len)
	{
		backup[i] = srcc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dest[i] = backup[i];
		i++;
	}
	return (dst);
}
