/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:51:28 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/25 17:39:40 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_print_number(t_prefix *pr, va_list ap)
{
	int			x;

	if (pr->t == 'i' || pr->t == 'd')
	{
		if (pr->s == 1)
			return (ft_print_nbr(ft_sign(va_arg(ap, long)), pr));
		else if (pr->s == 2)
			return (ft_print_nbr(ft_sign(va_arg(ap, long long)), pr));
		else if (pr->s == 3)
			return (ft_print_nbr(ft_sign((short)va_arg(ap, int)), pr));
		else if (pr->s == 4)
			return (ft_print_nbr(ft_sign((char)va_arg(ap, int)), pr));
		return (ft_print_nbr(ft_sign(va_arg(ap, int)), pr));
	}
	x = (pr->t == 'o' || pr->t == 'O') ? (8) : (10);
	x = (pr->t == 'x' || pr->t == 'X' || pr->t == 'p') ? (16) : (x);
	if (pr->s == 1 || pr->t == 'p')
		return (ft_print_nbr(ft_uns(va_arg(ap, unsigned long), x), pr));
	else if (pr->s == 2)
		return (ft_print_nbr(ft_uns(va_arg(ap, unsigned long long), x), pr));
	else if (pr->s == 3)
		return (ft_print_nbr(ft_uns((unsigned short)va_arg(ap, int), x), pr));
	else if (pr->s == 4)
		return (ft_print_nbr(ft_uns((unsigned char)va_arg(ap, int), x), pr));
	return (ft_print_nbr(ft_uns(va_arg(ap, unsigned int), x), pr));
}

int				ft_print_characters(t_prefix *pr, va_list ap)
{
	if (pr->t == 's')
		return (ft_print_s(pr, va_arg(ap, char*)));
	else if (pr->t == 'S')
		return (ft_print_ws(pr, (char*)va_arg(ap, int*)));
	else if (pr->t == 'c')
		return (ft_print_c(pr, (char)va_arg(ap, int)));
	else if (pr->t == 'C')
		return (ft_print_wc(pr, va_arg(ap, int)));
	return (0);
}

int				ft_print_global(t_prefix *pr, va_list ap)
{
	int			c;

	c = 0;
	if (!pr->t)
		c = 0;
	else if (pr->t == 's')
		c = ft_print_s(pr, va_arg(ap, char*));
	else if (pr->t == 'c' || pr->t == 'C')
		c = ft_print_c(pr, (char)va_arg(ap, int));
	else if (pr->t == 'd' || pr->t == 'i' || pr->t == 'X' || pr->t == 'x' ||
						pr->t == 'o' || pr->t == 'p' || pr->t == 'u')
		c = ft_print_number(pr, ap);
	else if (pr->t == 'f')
		c = pr->s == 5 ? ft_print_long_double(va_arg(ap, long double), pr) :
				ft_print_double(va_arg(ap, double), pr);
	else if (pr->t == '%')
		c = ft_print_percente(pr);
	else if (pr->t == 'b')
	{
		c = va_arg(ap, int);
		c = ft_lputstr(ft_read_memory((char*)&c, sizeof(int)));
	}
	if (pr->f)
		free(pr->f);
	return (c);
}

int				ft_printf(const char *format, ...)
{
	char		*to_manage;
	t_prefix	pr;
	int			count;
	va_list		ap;

	to_manage = (char*)format;
	count = 0;
	va_start(ap, format);
	while (*to_manage)
	{
		if (*to_manage != '%')
			count += ft_putchar(*to_manage++);
		else if (to_manage[1] == '%')
		{
			count += ft_putchar('%');
			to_manage += 2;
		}
		else
		{
			to_manage += ft_reconize_flag(to_manage + 1, &pr) + 1;
			count += ft_print_global(&pr, ap);
		}
	}
	va_end(ap);
	return (count);
}
