/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:01:01 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 19:19:18 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*bb;
	size_t	i;

	bb = (char*)b;
	i = 0;
	while (i < len)
		bb[i++] = (unsigned char)c;
	return (b);
}
