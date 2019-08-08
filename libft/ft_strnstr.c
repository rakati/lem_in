/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:01:41 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/07 18:51:01 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int		c;
	int		len;
	int		lenstr;
	size_t	i;
	char	*res;

	len = ft_strlen(to_find);
	lenstr = ft_strlen(str);
	i = 0;
	while (*str && i < n)
	{
		c = 0;
		while (str[c] == to_find[c] && str[c] != '\0' && c <= len &&
				(c + i) < n)
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
