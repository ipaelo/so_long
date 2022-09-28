/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:42:03 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/05 11:28:11 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			count;
	unsigned char	*aux;

	count = 0;
	aux = (unsigned char *)b;
	while (count < n)
	{
		aux[count] = (unsigned char)c;
		count++;
	}
	return (b);
}
