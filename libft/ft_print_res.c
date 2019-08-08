/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:18:02 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/25 21:26:46 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_put_sign(char *s, t_prefix *pr)
{
	int		c;

	c = 0;
	if (*s != '-' && (ft_strchr(pr->f, '+') || ft_strchr(pr->f, ' ')))
		c += ft_putchar((ft_strchr(pr->f, '+') ? '+' : ' '));
	else if (*s == '-')
		ft_putchar(*s++);
	if (pr->p > 0)
		c += ft_put_ntime('0', pr->p);
	else if (pr->w > 0 && ft_strchr(pr->f, '0') && !ft_strchr(pr->f, '-') &&
			pr->p < 0)
		c += ft_put_ntime('0', pr->w);
	ft_putstr(s);
	if (ft_strchr(pr->f, '-') && pr->w > 0)
		c += ft_put_ntime(' ', pr->w);
	return (c);
}

static	int	ft_put_uns(char *s, t_prefix *pr)
{
	int		c;

	c = 0;
	if (ft_strchr(pr->f, '#') && *s != '0' && pr->t == 'o')
		pr->p -= 1;
	if (ft_strchr(pr->f, '#') && *s != '0' && (*s || pr->t == 'o'))
		if ((c += ft_putchar('0')) && (pr->t == 'x' || pr->t == 'X'))
			c += ft_putchar(pr->t);
	if (pr->t == 'p')
		c += ft_lputstr("0x");
	if (pr->t == 'x' || pr->t == 'p')
		ft_strlowercase(s);
	if (pr->p > 0)
		c += ft_put_ntime('0', pr->p);
	else if (pr->w > 0 && ft_strchr(pr->f, '0') && !ft_strchr(pr->f, '-') &&
			pr->p < 0)
		c += ft_put_ntime('0', pr->w);
	ft_putstr(s);
	if (ft_strchr(pr->f, '-') && pr->w > 0)
		c += ft_put_ntime(' ', pr->w);
	return (c);
}

int			ft_print_nbr(char *s, t_prefix *pr)
{
	int		c;
	char	*p;

	p = s;
	if (*s == '0' && pr->p == 0)
		s = "";
	c = ft_strlen(s);
	if (pr->p != 0)
		pr->p -= (*s == '-') ? (c - 1) : (c);
	pr->w -= (pr->p > 0) ? (c + pr->p) : c;
	pr->w -= (((ft_strchr(pr->f, '+') || ft_strchr(pr->f, ' ')) && *s != '-') ||
	(ft_strchr(pr->f, '#') && *s != '0') || pr->t == 'p') ? 1 : 0;
	pr->w -= ((ft_strchr(pr->f, '#') && (pr->t == 'x' || pr->t == 'X') &&
				*s != '0') || pr->t == 'p') ? 1 : 0;
	if (pr->w > 0 && ((ft_strchr(pr->f, '0') && pr->p >= 0) ||
		(!ft_strchr(pr->f, '0') || pr->p == -1)) && !ft_strchr(pr->f, '-'))
		c += ft_put_ntime(' ', pr->w);
	if (pr->t == 'd' || pr->t == 'i')
		c += ft_put_sign(s, pr);
	else
		c += ft_put_uns(s, pr);
	free(p);
	return (c);
}
