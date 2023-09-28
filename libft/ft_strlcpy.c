/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:37:42 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/05 10:55:09 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* function copies up to size - 1 characters from the NUL-terminated string */
/*src to dst, NUL-terminating the result. */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	c;
	size_t			count_src;

	count_src = 0;
	while (src[count_src] != '\0')
	{
		++count_src;
	}
	c = 0;
	if (dstsize > 0)
	{
		while (src[c] != '\0' && c < dstsize - 1)
		{
			dst[c] = src[c];
			c++;
		}
	}
	else
		return (count_src);
	dst[c] = '\0';
	return (count_src);
}
