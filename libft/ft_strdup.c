/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:32:10 by itorres-          #+#    #+#             */
/*   Updated: 2022/04/28 09:47:06 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*Se asegura que hay espacio suficente para la copia de s1,
	lo copia y devuelve el puntero a la copia */

char	*ft_strdup(const char *s1)
{
	int		len_out;
	int		count;
	char	*out;

	len_out = ft_strlen(s1) + 1;
	out = malloc(len_out * sizeof(char));
	if (out == NULL)
		return (NULL);
	count = 0;
	while (s1[count] != '\0')
	{
		out[count] = s1[count];
		count++;
	}
	out[count] = '\0';
	return (out);
}
