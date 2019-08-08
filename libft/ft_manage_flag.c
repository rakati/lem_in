/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:01:30 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/14 23:21:00 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_parametre(t_prefix *pr, char *s)
{
	int i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '$')
	{
		pr->d = ft_atoi(s);
		return (i + 1);
	}
	else
		pr->d = 0;
	return (0);
}

static int		check_width(t_prefix *pr, char *s)
{
	int i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	pr->w = ft_atoi(s);
	return (i);
}

static int		check_precision(t_prefix *pr, char *s)
{
	int i;

	i = 0;
	pr->p = -1;
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		pr->p = ft_atoi(&s[1]);
		return (i);
	}
	return (0);
}

static int		check_type(t_prefix *pr, char *s)
{
	char		*p;
	int			i;
	int			c;

	i = 0;
	p = "cCspdiouxXfb%";
	pr->s = 0;
	if (s[i] == 'l' || s[i] == 'h')
		pr->s = (s[i++] == 'l') ? (1) : (3);
	if ((s[i] == 'l' && s[i - 1] == 'l') || (s[i] == 'h' && s[i - 1] == 'h'))
		pr->s = (s[i++] == 'l') ? (2) : (4);
	else if (s[i] == 'L')
	{
		pr->s = 5;
		i++;
	}
	c = -1;
	while (p[++c])
		if (p[c] == s[i])
		{
			pr->t = s[i];
			return (i + 1);
		}
	return (0);
}

int				ft_reconize_flag(char *s, t_prefix *pr)
{
	int			i;
	int			count;

	count = 0;
	s += (i = check_parametre(pr, s));
	count += i;
	i = 0;
	while (s[i] == '#' || s[i] == '+' || s[i] == '-'\
						|| s[i] == ' ' || s[i] == '0')
		i++;
	count += i;
	pr->f = ft_strndup(s, i);
	s += i;
	s += (i = check_width(pr, s));
	count += i;
	s += (i = check_precision(pr, s));
	count += i;
	count += check_type(pr, s);
	return (count);
}
