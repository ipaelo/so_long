/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:56:43 by itorres-          #+#    #+#             */
/*   Updated: 2022/04/28 10:35:15 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	c;
	int	minus;

	result = 0;
	c = 0;
	minus = 1;
	while (str[c] && (str[c] == ' ' || str[c] == '\n' || str[c] == '\t'
			|| str[c] == '\v' || str[c] == '\f' || str[c] == '\r'))
			c++;
	if (str[c] && (str[c] == '-' || str[c] == '+'))
	{
		if (str[c] == '-')
			minus *= -1;
		c++;
	}
	while (str[c] && (str[c] >= '0' && str[c] <= '9'))
	{
		result = (result * 10) + (str[c] - '0');
		c++;
	}
	return (result * minus);
}
