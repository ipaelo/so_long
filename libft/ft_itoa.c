/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:09:11 by itorres-          #+#    #+#             */
/*   Updated: 2022/09/27 13:20:47 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* De int a Str usa la auxiliar ft_intlen para saber el tamaño de int */

static int	ft_intlen(long int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long int	aux;

	aux = n;
	count = ft_intlen(n);
	str = (char *)malloc(count * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (aux == 0)
		str[0] = '0';
	if (aux < 0)
	{	
		str[0] = '-';
		aux = aux * -1;
	}
	while (aux > 0)
	{
		str[count-- - 1] = ((aux % 10) + '0');
		aux = aux / 10;
	}
	return (str);
}
