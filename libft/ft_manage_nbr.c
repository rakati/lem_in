/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:32:32 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/04 15:49:55 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_sign(long long dec)
{
	int		i;
	char	res[23];
	char	*copy;
	char	s;

	if (dec < -9223372036854775807 || dec == 0)
		return (ft_strdup(dec == 0 ? "0" : "-9223372036854775808"));
	s = (dec < 0) ? ('-') : ('\0');
	if (dec < 0)
		dec *= -1;
	i = 0;
	while (dec > 0)
	{
		res[i++] = (dec % 10 <= 9) ? (dec % 10 + '0') : (dec % 10 - 10 + 'A');
		dec /= 10;
	}
	res[i++] = s;
	res[i] = '\0';
	ft_strrev(res);
	copy = ft_strdup(res);
	return (copy);
}

char		*ft_uns(unsigned long long dec, int base)
{
	int		i;
	char	res[23];
	char	*copy;

	if (dec == 0)
		return (ft_strdup("0"));
	i = 0;
	while (dec > 0)
	{
		res[i++] = (dec % base <= 9) ? (dec % base + '0') :
			(dec % base - 10 + 'A');
		dec /= base;
	}
	res[i] = '\0';
	ft_strrev(res);
	copy = ft_strdup(res);
	return (copy);
}
