/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:05:25 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/07/23 18:44:25 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char*)malloc((size + 1) * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
