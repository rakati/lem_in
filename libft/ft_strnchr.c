/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:21:12 by abiri             #+#    #+#             */
/*   Updated: 2019/02/10 16:54:38 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		if (c == s[i++])
			return ((char *)(s + i - 1));
	return (NULL);
}
