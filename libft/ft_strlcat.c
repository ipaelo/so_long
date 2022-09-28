/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:18:09 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/04 13:26:22 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lcount;
	size_t	count;
	size_t	result;

	count = 0;
	lcount = ft_strlen(dst);
	result = ft_strlen(src);
	if (dstsize <= lcount)
		result = result + dstsize;
	else
		result = result + lcount;
	while (src[count] != '\0' && (lcount + 1) < dstsize)
	{
		dst[lcount] = src[count];
		count++;
		lcount++;
	}
	dst[lcount] = '\0';
	return (result);
}
