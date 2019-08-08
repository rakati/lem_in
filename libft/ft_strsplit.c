/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 22:23:48 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/09 13:49:36 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			nbr_of_words(const char *str, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	if (str[i] != c)
		words++;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (str[i - 1] == c)
				words++;
		}
		i++;
	}
	return (words);
}

int			*char_in_word(int *t, const char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && str[i] != '\0')
		{
			t[j] = 0;
			while (str[i] != c && str[i] != '\0')
			{
				t[j]++;
				i++;
			}
			j++;
		}
		if (str[i] == c && str[i] != '\0')
			i++;
	}
	t[j] = 0;
	return (t);
}

char		**ft_asssign(char **splited, const char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	while (*str)
	{
		if (*str != c && *str != '\0')
		{
			j = 0;
			while (*str != c && *str != '\0')
			{
				splited[i][j] = *str;
				j++;
				str++;
			}
			splited[i][j] = '\0';
			i++;
		}
		if (*str == c && *str != '\0')
			str++;
	}
	splited[i] = 0;
	return (splited);
}

char		**ft_strsplit(const char *s, char c)
{
	int		*t;
	char	**splited;
	int		j;
	int		i;

	if (s == 0)
		return (0);
	t = (int*)malloc((nbr_of_words(s, c) + 1) * sizeof(int));
	splited = (char**)malloc((nbr_of_words(s, c) + 1) * sizeof(char*));
	if (splited == 0)
		return (0);
	t = char_in_word(t, s, c);
	j = 0;
	while (t[j])
	{
		splited[j] = (char*)malloc(t[j] * sizeof(char));
		if (splited[j] == 0)
			return (0);
		j++;
	}
	i = 0;
	splited = ft_asssign(splited, s, c);
	return (splited);
}
