/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:26:07 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 21:18:08 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			cond_max_long(const char *str)
{
	int		len;

	len = 0;
	while (str[len] > 47 && str[len] < 58)
		len++;
	return (len);
}

int			ft_atoi(const char *str)
{
	size_t	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r' ||
			*str == '\f' || *str == '\v' || *str == '\n')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = -1;
	}
	if (cond_max_long(str) > 10)
		return (sign < 0 ? 0 : -1);
	while (*str > 47 && *str < 58)
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
