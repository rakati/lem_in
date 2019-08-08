/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:24:12 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/05 17:16:58 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Read  he
*/

char		*ft_get_file_content(int fd, int size)
{
	char	*content;
	int		r;
	int		step;
	int		i;

	if (!(content = ft_strnew(size)))
		return (NULL);
	step = size / 2;
	i = 0;
	while ((r = read(fd, content + i, step)))
	{
		if (r < 0)
		{
			free(content);
			return (NULL);
		}
		i += r;
		if (i + step >= size)
		{
			content = ft_realloc(content, size, (size * 3) / 2, sizeof(char));
			size = (size * 3) / 2;
		}
	}
	return (content);
}
