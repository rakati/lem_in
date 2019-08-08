/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:10:08 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/05 17:12:03 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	read and store number of ants
**	return position to start of next line
**	otherwise if an error occur the function exit and free all memory malloced
*/

int			ft_read_ants_nbr(t_container *cont)
{
	int		pos;

	pos = 0;
	while (cont->content[pos] != '\n')
	{
		if (!ft_isdigit(cont->content[pos]) && pos >= 10)
			ft_free_exit(cont, RED("Invalid number of ants"));
		cont->nbr_ants = cont->nbr_ants * 10 + (cont->content[pos] - '0');
		pos++;
	}
	if (cont->nbr_ants <= 0)
		ft_free_exit(cont, RED("Invalid number of ants"));
	return (pos + 1);
}

/*
**	check the form of coordinates (must be a number and containe two numbers)
**	return position to the next line
**	otherwise if an error occur the function exit and free all memory malloced
*/

int			ft_check_coordinates(t_container *cont, int curr)
{
	int		pos;
	int		error;

	pos = curr;
	error = 0;
	if (cont->content[pos] == '-')
		pos++;
	while (cont->content[pos] != ' ' && cont->content[pos] != '\n' &&
			cont->content[pos] && ft_isdigit(cont->content[pos]))
		pos++;
	if (cont->content[pos] != ' ')
		error = 1;
	pos++;
	if (cont->content[pos] == '-')
		pos++;
	while (cont->content[pos] != ' ' && cont->content[pos] != '\n' &&
			cont->content[pos] && ft_isdigit(cont->content[pos]) && !error)
		pos++;
	if (error || cont->content[pos] != '\n' || !cont->content[pos])
		ft_free_exit(cont, RED("Invalid coordinations of room"));
	return (pos + 1);
}

/*
**	skip comment and store next room as start or end depend on comment
**	return position to line after comment
**	otherwise if an error occur the function exit and free all memory malloced
*/

int			ft_read_comment(t_container *cont, int line)
{
	int		pos;
	int		name;

	pos = 0;
	while (cont->content[line + pos] != '\n' && cont->content[line + pos])
		pos++;
	if (cont->content[line + 1] == '#' &&
			(name = ft_findchar(cont->content + line + pos + 1, ' ')) > 0)
	{
		if (cont->content[line + pos + 1] == '#')
			ft_free_exit(cont, RED("invalid room"));
		if (ft_strncmp("##start", cont->content + line, pos) == 0)
		{
			if (cont->source)
				ft_free_exit(cont, RED("duplicate room start"));
			cont->source = ft_strndup(cont->content + line + pos + 1, name);
		}
		else if (ft_strncmp("##end", cont->content + line, pos) == 0)
		{
			if (cont->sink)
				ft_free_exit(cont, RED("duplicate room end"));
			cont->sink = ft_strndup(cont->content + line + pos + 1, name);
		}
	}
	return (pos + 1);
}

/*
**	parse room's name from input,check name form and insert it to hash_table,
**	with checking of input format.
**	return position to line with room's connection start
**	otherwise if an error occur the function exit and free all memory malloced
*/

int			ft_read_rooms(t_container *c, int line)
{
	int		pos;
	t_room	*new_room;

	while (c->content[line])
	{
		pos = 0;
		if (c->content[line] == '#')
		{
			line += ft_read_comment(c, line);
			continue ;
		}
		while (c->content[line + pos] != ' ' && c->content[line + pos] != '\n'
				&& c->content[line + pos] && c->content[line + pos] != '-')
			pos++;
		if (c->content[pos + line] == '-')
			return (line);
		if (c->content[pos + line] != ' ' || c->content[line] == 'L')
			ft_free_exit(c, RED("Invalid Room name and coord structure"));
		if (!(new_room = ft_new_t_room(c->content + line, pos)))
			ft_free_exit(c, RED("Can't allocate t_str"));
		if (!(ft_insert_value(c->hash_table, new_room, c->power)))
			ft_free_exit(c, RED("Bad Insertion"));
		line = ft_check_coordinates(c, line + pos + 1);
	}
	return (line);
}
