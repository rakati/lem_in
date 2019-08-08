/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:07:45 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/06 20:27:56 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# define H_SIZE 4001

/*
** debuging defines
*/

# define EX exit(120);
# define DEB1 ft_printf("HERE : 1\n");
# define DEB2 ft_printf("HERE : 2\n");
# define DEB3 ft_printf("HERE : 3\n");
# define DEB4 ft_printf("HERE : 4\n");
# define DEB5 ft_printf("HERE : 5\n");

typedef struct		s_room
{
	char			*name;
	int				vis:1;
	t_addr			*neighbors;
	int				degree;
	int				level;
	struct s_room	*father;
}					t_room;

typedef struct		s_hash
{
	t_room			*room;
	struct s_hash	*next;
}					t_hash;

typedef struct		s_container
{
	char			*content;
	int				nbr_ants;
	t_hash			**hash_table;
	t_room			*source;
	t_room			*sink;
	long long		power[101];
}					t_container;

/*
** operation on hash table map of key and values
*/

long long			ft_hash(char *str, long long *power);
t_hash				*ft_new_t_hash(t_room *room_addr);
int					ft_insert_value(t_hash **hash_table, t_room *new_room,
					long long *power);
t_room				*ft_get_value(t_hash **hash_table, char *key,
					long long *power);
void				ft_free_hash_table(t_hash **hash_table);
void				print_hash_table(t_hash **hash_table);

/*
** parsing function
*/

void				store_rooms(t_container *container);

int					ft_read_ants_nbr(t_container *cont);
int					ft_check_coordinates(t_container *cont, int curr);
int					ft_read_comment(t_container *cont, int line);
int					ft_read_rooms(t_container *c, int line);

int					set_connection(t_room *room1, t_room *room2);
int					get_relations(t_container *c, int line);

/*
** small tools
*/

void				ft_free_exit(t_container *cont, char *error);
t_room				*ft_new_t_room(char *s, int len);
void				ft_free_t_room(t_room *head);

#endif
