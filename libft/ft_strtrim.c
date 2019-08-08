/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 22:06:31 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/09 13:48:00 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	char	*str_trimed;

	if (s == 0)
		return (0);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	if (*s == '\0')
		return ("");
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	str_trimed = (char*)malloc((len + 1) * sizeof(char));
	if (str_trimed == 0)
		return (0);
	str_trimed[len] = '\0';
	while (len > 0)
	{
		str_trimed[len - 1] = s[len - 1];
		len--;
	}
	return (str_trimed);
}
