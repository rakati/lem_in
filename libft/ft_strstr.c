/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:33:26 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/09 13:47:41 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int		c;
	int		len;
	int		i;
	char	*res;

	if (*to_find == '\0')
		return ((char*)str);
	len = ft_strlen(to_find);
	i = 0;
	while (*str)
	{
		c = 0;
		while (str[c] == to_find[c] && str[c] != '\0' && c <= len)
			c++;
		if (c == len)
		{
			res = (char*)malloc((len - i) * sizeof(char));
			res = (char*)str;
			return (res);
		}
		str++;
		i++;
	}
	return (0);
}
