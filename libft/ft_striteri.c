/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:09:59 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/05 13:05:13 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*A cada carácter de la string ’s’, aplica la función ’f’ como parámetros*/
/* el índice de cada carácter dentro de ’s’ y la dirección del propio carácter*/
/* que podrá modificarse si es necesario.*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		count;

	count = 0;
	if (s && f)
	{
		while (s[count] != '\0')
		{
			f(count, &s[count]);
			count++;
		}	
	}
}
