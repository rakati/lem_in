/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:18:02 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/04 15:22:16 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char *src, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char*)malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		res[i] = src[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}
