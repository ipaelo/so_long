/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:18:59 by itorres-          #+#    #+#             */
/*   Updated: 2022/04/28 11:14:57 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;
	size_t			i;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (aux_s1[i] > aux_s2[i])
		{
			return (aux_s1[i] - aux_s2[i]);
		}
		else if (aux_s1[i] < aux_s2[i])
		{
			return (aux_s1[i] - aux_s2[i]);
		}
		i++;
	}
	return (0);
}
