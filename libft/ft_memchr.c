/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:02:35 by itorres-          #+#    #+#             */
/*   Updated: 2022/04/27 15:32:53 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux;
	size_t			count;

	aux = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		if (aux[count] == (unsigned char)c)
			return (&aux[count]);
		count++;
	}
	return (0);
}
