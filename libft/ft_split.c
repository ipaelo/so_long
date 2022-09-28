/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:08:47 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/13 15:55:32 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Divide un string en substrings con un separador c */

/* Contador de palabras */

static int	ft_counter(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*str)
	{
		if (*str != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*str == c)
			i = 0;
		str++;
	}
	return (count);
}

/* Extrae palabras de Str con pos inicial y pos final */

static char	*ft_extracter_word(const char *str, int s, int f)
{
	char	*pal;
	int		i;

	pal = malloc((f - s + 1) * sizeof(char));
	i = 0;
	while (s < f)
	{
		pal[i++] = str[s++];
	}
	pal[i] = '\0';
	return (pal);
}

static char	**ft_init(char const *s, char c)
{
	char	**splitted;

	if (!s)
		return (0);
	splitted = malloc((ft_counter(s, c) + 1) * sizeof(char *));
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**splitted;

	splitted = ft_init(s, c);
	if (!splitted)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			splitted[j++] = ft_extracter_word(s, index, i);
			index = -1;
		}
		i++;
	}
	splitted[j] = 0;
	return (splitted);
}
