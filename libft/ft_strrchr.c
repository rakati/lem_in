/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:36:10 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/07 18:14:44 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*ss;
	int		i;

	ss = (char*)s;
	i = ft_strlen(ss);
	while (i >= 0)
	{
		if (ss[i] == c)
			return (&ss[i]);
		i--;
	}
	return (0);
}
