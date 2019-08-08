/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:26:28 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/01 17:06:22 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long long		ft_hash(char *str, long long *power)
{
	long long	p;
	long long	hash;
	int			i;

	p = 53;
	i = 0;
	hash = 0;
	while (str[i] && i < 100)
	{
		if (power[i] == 0)
			power[i] = ft_binpow(p, i, H_SIZE);
		hash += power[i] * str[i] % H_SIZE;
		i++;
	}
	return (hash);
}

t_hash			*ft_new_t_hash(t_room *room_addr)
{
	t_hash		*new;

	if (!(new = (t_hash*)malloc(sizeof(t_hash))))
		return (NULL);
	new->room = room_addr;
	new->next = NULL;
	return (new);
}

int				ft_insert_value(t_hash **hash_table, t_room *new_room,
				long long *power)
{
	long long	hash;
	t_hash		*curr;

	hash = ft_hash(new_room->name, power) % H_SIZE;
	if (hash_table[hash] == NULL)
	{
		if (!(hash_table[hash] = ft_new_t_hash(new_room)))
			return (0);
	}
	else
	{
		curr = hash_table[hash];
		while (curr->next && ft_strcmp(curr->room->name, new_room->name) != 0)
			curr = curr->next;
		if (ft_strcmp(curr->room->name, new_room->name) != 0)
		{
			if (!(curr->next = ft_new_t_hash(new_room)))
				return (0);
		}
		else
			ft_free_t_room(new_room);
	}
	return (1);
}

t_room			*ft_get_value(t_hash **hash_table, char *key, long long *power)
{
	long long	hash;
	t_hash		*curr;

	hash = ft_hash(key, power) % H_SIZE;
	curr = hash_table[hash];
	while (curr && ft_strcmp(key, curr->room->name) != 0)
		curr = curr->next;
	return (curr ? curr->room : NULL);
}

void			ft_free_hash_table(t_hash **hash_table)
{
	int			i;
	t_hash		*curr;
	t_hash		*next;

	i = 0;
	while (i < H_SIZE)
	{
		if (hash_table[i] != NULL)
		{
			curr = hash_table[i];
			while (curr != NULL)
			{
				next = curr->next;
				ft_free_t_room(curr->room);
				free(curr);
				curr = next;
			}
		}
		i++;
	}
}
