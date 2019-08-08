/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 23:12:40 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/21 23:16:55 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar(int unicode)
{
	if (unicode <= 0x7f)
		ft_putchar(unicode);
	else if (unicode <= 0x7ff)
	{
		ft_putchar((unicode >> 6) | 192);
		ft_putchar((unicode & 63) | 128);
		return (2);
	}
	else if (unicode <= 0xffff)
	{
		ft_putchar((unicode >> 12) | 224);
		ft_putchar(((unicode >> 6) & 63) | 128);
		ft_putchar((unicode & 63) | 128);
		return (3);
	}
	else if (unicode <= 0x1fffff)
	{
		ft_putchar((unicode >> 18) | 240);
		ft_putchar(((unicode >> 12) & 63) | 128);
		ft_putchar(((unicode >> 6) & 63) | 128);
		ft_putchar((unicode & 63) | 128);
		return (4);
	}
	return (1);
}
