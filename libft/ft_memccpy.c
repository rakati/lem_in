/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:08:19 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/07 15:32:19 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	size_t			i;
	unsigned char	*ptr2;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	i = 0;
	while ((i < n) && (ptr2[i] != (unsigned char)c))
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	if (ptr2[i] == (unsigned char)c)
	{
		ptr1[i] = (unsigned char)c;
		return (dst + (i + 1));
	}
	return (NULL);
}
