/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:02:23 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/07 18:14:40 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *ss;

	ss = (char*)s;
	while (*ss)
	{
		if (*ss == (char)c)
			return (ss);
		ss++;
	}
	if ((char)c == '\0')
		return (ss);
	return (0);
}
