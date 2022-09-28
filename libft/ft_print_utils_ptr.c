/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:37:36 by itorres-          #+#    #+#             */
/*   Updated: 2022/06/17 12:51:00 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_length_ptr(uintptr_t n)
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

void	ft_put_ptr_aux(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_ptr_aux(n / 16);
		ft_put_ptr_aux(n % 16);
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
			n = n + 87;
			write(1, &n, 1);
		}
	}
}

int	ft_put_ptr(unsigned long long n)
{
	int	count;

	count = 0;
	count += (write(1, "0x", 2));
	if (n == 0)
		count += (write(1, "0", 1));
	else
	{
		ft_put_ptr_aux(n);
		count += ft_length_ptr(n);
	}
	return (count);
}
