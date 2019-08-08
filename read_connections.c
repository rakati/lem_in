/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_connections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:21:54 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/05 17:11:55 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** The function set_connection add a relationship to the room1 with room2 and
** andvice versa.
** return 1 if connection seted otherwise return 0 for an error.
*/

int		set_connection(t_room *room1, t_room *room2)
{
	int	added;

	if (!room1 || !room2)
		return (0);
	if (room1 != room2)
	{
		room1->neighbors = ft_push_t_addr(room1->neighbors, room2, &added);
		if (added)
			room1->degree++;
		room2->neighbors = ft_push_t_addr(room2->neighbors, room1, &added);
		if (added)
			room2->degree++;
		if (!room1->neighbors || !room2->neighbors)
			return (0);
	}
	return (1);
}

/*
** The function get first get the first part of the realtion and prepare it to
** be added to the relationshop list !
*/

char	*get_first(t_container *c, int *pos, int line)
{
	char	*temp;

	while (c->content[line + (*pos)] != '-' && c->content[line + (*pos)] != '\n'
			&& c->content[line + (*pos)] != ' ' && c->content[line + (*pos)])
		(*pos)++;
	if (c->content[line + (*pos)] != '-')
		ft_free_exit(c, RED("invalid connection between rooms"));
	temp = ft_strndup(c->content + line, (*pos));
	return (temp);
}

/*
** The function get second get the second part of the realtion and prepare it to
** be added to the relationshop list !
*/

char	*get_second(t_container *c, int *pos, int line, int first_break)
{
	char	*temp;

	(*pos)++;
	while (c->content[line + (*pos)] != '\n' && c->content[line + (*pos)] &&
		c->content[line + (*pos)] != ' ' && c->content[line + (*pos)] != '-')
		(*pos)++;
	if (c->content[line + (*pos)] != '\n')
		ft_free_exit(c, RED("invalid connection between rooms"));
	temp = ft_strndup(c->content + line + first_break, (*pos) - first_break);
	return (temp);
}

/*
** The function that read every line from the input and read the rooms
** while checker bad relationships between rooms and the start and the end
** rooms !
*/

int		get_relations(t_container *c, int line)
{
	int		pos;
	char	*temp;
	t_room	*room1;
	t_room	*room2;
	int		first_break;

	while (c->content[line])
	{
		pos = 0;
		if (c->content[line] == '#')
		{
			line += ft_read_comment(c, line);
			continue ;
		}
		temp = get_first(c, &pos, line);
		first_break = pos + 1;
		room1 = ft_get_value(c->hash_table, temp, c->power);
		free(temp);
		temp = get_second(c, &pos, line, first_break);
		room2 = ft_get_value(c->hash_table, temp, c->power);
		free(temp);
		set_connection(room1, room2);
		line += pos + 1;
	}
	return (1);
}
