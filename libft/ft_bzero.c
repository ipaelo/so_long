/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:40:11 by itorres-          #+#    #+#             */
/*   Updated: 2022/04/27 13:47:47 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)

{
	size_t			count;
	unsigned char	*aux;

	count = 0;
	aux = (unsigned char *)s;
	while (count < n)
	{
		aux[count] = 0;
		count++;
	}
}
