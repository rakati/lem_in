/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:40 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/10 19:27:31 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_read_memory(char *p, int bytes)
{
	char	*res;
	int		shift;
	size_t	i;

	res = (char*)malloc((bytes * 8 + 1) * sizeof(char));
	i = 0;
	while (bytes-- > 0)
	{
		shift = 0;
		while (shift < 8)
		{
			res[i++] = (*p >> shift & 1) ? '1' : '0';
			shift++;
		}
		p++;
	}
	res[i] = '\0';
	ft_strrev(res);
	return (res);
}
