/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:27:48 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/06 15:39:50 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Devuelve un puntero lleno de 0 con n elementos de tamaño size */

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((count == SIZE_MAX && size > 1) || (size == SIZE_MAX && count > 1))
		return (0);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
