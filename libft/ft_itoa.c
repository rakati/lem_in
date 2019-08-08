/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:17:49 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 21:39:13 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_intlen(int n)
{
	int		res;

	res = 0;
	if (n < 0)
		res++;
	if (n == 0)
		return (1);
	while (n)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		l;
	int		j;

	l = ft_intlen(n);
	if (!(res = (char*)malloc((l + 1) * sizeof(char))))
		return (0);
	res[l] = '\0';
	if (l == 1)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		j = 1;
	}
	else
		j = 0;
	while (l-- > j)
	{
		res[l] = '0' + (n % 10) * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (res);
}
