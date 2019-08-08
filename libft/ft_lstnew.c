/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:13:09 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/10 20:56:56 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	if (!(fresh = (t_list*)malloc((content_size) * sizeof(t_list))))
		return (NULL);
	fresh->next = NULL;
	if (content == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
		return (fresh);
	}
	if (!(fresh->content = (void*)malloc(content_size * sizeof(void*))))
		return (NULL);
	fresh->content = ft_memmove(fresh->content, content, content_size);
	fresh->content_size = content_size;
	return (fresh);
}
