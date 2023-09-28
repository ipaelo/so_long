/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:14:19 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/04 14:50:08 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Devuelve un puntero a la última aparición de needle en haystack */
/*con un máximo de len caracteres en haystack*/
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	size_t	c2;

	c = 0;
	c2 = 0;
	if (needle[c] == '\0')
		return ((char *)haystack);
	while ((haystack[c] != '\0') && (c < len))
	{
		c2 = 0;
		while ((haystack[c + c2] == needle[c2]) && (c + c2 < len))
		{
			if (needle[c2 + 1] == '\0')
				return ((char *)&haystack[c]);
			c2++;
		}
		c++;
	}
	return (0);
}
