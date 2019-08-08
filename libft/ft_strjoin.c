/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:58:41 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/09 13:50:33 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*s1s2;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	s1s2 = (char*)malloc((len + 1) * sizeof(char));
	if (s1s2 == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		s1s2[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		s1s2[i++] = *s2;
		s2++;
	}
	s1s2[i] = '\0';
	return (s1s2);
}
