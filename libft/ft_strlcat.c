/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:18:09 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 21:27:10 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_l;
	size_t	src_l;
	size_t	res;
	size_t	j;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	res = 0;
	j = 0;
	if (size <= dest_l)
		res = src_l + size;
	else
		res = src_l + dest_l;
	while (src[j] && dest_l + 1 < size)
		dest[dest_l++] = src[j++];
	dest[dest_l] = '\0';
	return (res);
}
