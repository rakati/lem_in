/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_to_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:14:57 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/06 14:43:15 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			base_to_dec(char *nbr, int base)
{
	size_t	len;
	size_t	i;
	int		res;

	len = ft_strlen(nbr);
	res = 0;
	i = 0;
	while (i < len)
	{
		res += (nbr[i] - 48) * ft_pow(base, len - i - 1);
		i++;
	}
	return (res);
}
