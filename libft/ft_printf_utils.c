/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:10:50 by itorres-          #+#    #+#             */
/*   Updated: 2022/06/17 13:45:27 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_length_number(int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
	{
		return (11);
	}
	if (n < 0)
	{
		n = n * -1;
		c++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		c++;
		n = (n / 10);
	}
	return (c);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	c;

	c = n;
	if (c == -2147483648)
	{
		write(fd, "-2", 2);
		c = 147483648;
	}
	if (c < 0)
	{
		write(fd, "-", 1);
		c = c * -1;
	}
	if (c < 10)
	{
		c = c + '0';
		write(fd, &c, 1);
	}
	else if (c >= 10)
	{
		ft_putnbr_fd((c / 10), fd);
		ft_putnbr_fd((c % 10), fd);
	}
}

int	ft_putnbr_pre_fd(unsigned int n)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_putnbr_fd(n, 1);
	return (ft_length_number(n));
}

int	ft_length_number_u(unsigned int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		c++;
		n = (n / 10);
	}
	return (c);
}

void	ft_putnbr_fd_u(unsigned int n, int fd)
{
	unsigned int	c;

	c = n;
	if (c < 10)
	{
		c = c + '0';
		write(fd, &c, 1);
	}
	else if (c >= 10)
	{
		ft_putnbr_fd_u((c / 10), fd);
		ft_putnbr_fd_u((c % 10), fd);
	}
}
