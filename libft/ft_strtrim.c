/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:08:25 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/16 10:48:11 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Devuelve 1 si c está en set */

int	ft_setsep(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

/* Devuelve una cadena con el primer char que no está en set desde el inicio */
/* y por el final*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		f;
	int		count;

	count = 0;
	i = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	f = (int)ft_strlen(s1);
	while (s1[i] && ft_setsep(s1[i], set))
		i++;
	while (f > i && ft_setsep(s1[f - 1], set))
		f--;
	str = (char *)malloc(sizeof(char) * (f - i + 1));
	if (!str)
		return (NULL);
	while (i < f)
		str[count++] = s1[i++];
	str[count] = '\0';
	return (str);
}
