/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:27:51 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/09 11:32:32 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Find first apparence of c in str */

char	*ft_strchr(const char *str, int c)
{
	char	*aux;

	aux = (char *)str;
	while (*aux)
	{
		if (*aux == (char) c)
			return (aux);
		aux++;
	}
	if ((char)c == *aux)
		return (aux);
	return (NULL);
}
