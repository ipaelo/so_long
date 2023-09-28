/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:56:23 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/09 11:28:45 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Devuelve un puntero a la última aparición de int c en *str */

static int	ft_counter(char *str, char c)
{
	int	count1;
	int	count_c1;

	count1 = 0;
	count_c1 = 0;
	while (str[count1] != '\0')
	{
		if (str[count1] == c)
			count_c1++;
		count1++;
	}
	return (count_c1);
}

char	*ft_strrchr(const char *str, int c)
{
	char	*aux;
	int		count_c;

	aux = (char *)str;
	count_c = ft_counter(aux, (char) c);
	if (aux == NULL)
		return (NULL);
	while (*aux)
	{
		if (*aux == (char) c)
		{
			count_c--;
			if (count_c == 0)
				return (aux);
		}
		aux++;
	}
	if ((char)c == *aux)
		return (aux);
	return (0);
}
