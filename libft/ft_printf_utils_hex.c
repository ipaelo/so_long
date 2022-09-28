/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:14:21 by itorres-          #+#    #+#             */
/*   Updated: 2022/06/17 12:49:37 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_length_hex(unsigned int n)
{
	int	c;

	c = 0;
	while (n != 0)
	{
		c++;
		n = (n / 16);
	}
	return (c);
}

void	ft_put_hex_aux(unsigned int n, const char select)
{
	if (n >= 16)
	{
		ft_put_hex_aux((n / 16), select);
		ft_put_hex_aux((n % 16), select);
	}
	else
	{
		if (n < 10)
		{
			n = n + '0';
			write(1, &n, 1);
		}
		else
		{
			if (select == 'x')
				n = n + 87;
			else
				n = n + 55;
			write(1, &n, 1);
		}
	}
}

int	ft_put_hex(unsigned int n, const char select)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex_aux(n, select);
	return (ft_length_hex(n));
}
