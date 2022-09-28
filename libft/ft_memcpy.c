/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:00:41 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/04 14:47:43 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copia src en dst con un tamaño máximo de n*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*aux_dest;
	char	*aux_src;
	size_t	c;

	c = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	aux_dest = (char *)dst;
	aux_src = (char *)src;
	while (c < n)
	{
		aux_dest[c] = aux_src[c];
		c++;
	}
	return (aux_dest);
}
