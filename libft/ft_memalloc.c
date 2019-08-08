/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:39:02 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 21:34:32 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *place;

	place = (void*)malloc(size * sizeof(void));
	if (place == 0)
		return (0);
	ft_bzero(place, size);
	return (place);
}
