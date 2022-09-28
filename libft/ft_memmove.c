/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:55:54 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/04 11:32:56 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*aux_dest;
	unsigned char	*aux_src;
	size_t			c;

	c = 0;
	aux_dest = (unsigned char *)dst;
	aux_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (aux_dest > aux_src)
	{
		while (len-- > 0)
		{
			aux_dest[len] = aux_src[len];
		}
	}
	else
	{
		while (c < len)
		{
			aux_dest[c] = aux_src[c];
			c++;
		}
	}
	return (aux_dest);
}
