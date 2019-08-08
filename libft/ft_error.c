/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 01:27:50 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/07/30 15:40:36 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_error(char *error_msg)
{
	char *p;

	p = YELLOW("ERROR : ");
	while (*p)
		write(2, p++, 1);
	p = error_msg;
	while (*p)
		write(2, p++, 1);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
