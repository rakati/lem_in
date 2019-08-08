/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:50:55 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/07 15:42:16 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = ft_strlen(src);
	j = 0;
	p = (char *)malloc(i + 1);
	if (p == NULL)
		return (NULL);
	while (j <= i)
	{
		p[j] = src[j];
		j++;
	}
	return (p);
}
