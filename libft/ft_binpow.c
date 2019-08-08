/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binpow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:48:21 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/07/30 15:08:10 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_binpow(long long n, int pow, long long mod)
{
	long long res;

	res = 1;
	n %= mod;
	while (pow)
	{
		if (pow & 1)
			res = res * n % mod;
		n = n * n % mod;
		pow >>= 1;
	}
	return (res);
}
