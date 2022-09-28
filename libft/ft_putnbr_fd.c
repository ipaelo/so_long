/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:48:40 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/05 12:02:09 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
