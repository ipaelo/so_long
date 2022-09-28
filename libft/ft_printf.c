/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:54:59 by itorres-          #+#    #+#             */
/*   Updated: 2022/06/17 13:45:32 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdarg.h>

int	ft_putchar_int(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_int(char *s)
{
	int	c;

	c = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (s[c] != '\0')
		{
			write(1, &s[c], 1);
			c++;
		}
	}
	return (c);
}

int	ft_printf_ft(va_list ptr, const char ft)
{
	int	i;
	int	temp;

	i = 0;
	if (ft == '%')
		i += write(1, "%", 1);
	else if (ft == 'c')
		i += ft_putchar_int(va_arg(ptr, int));
	else if (ft == 's')
		i += ft_putstr_int(va_arg(ptr, char *));
	else if ((ft == 'i') || (ft == 'd'))
		i += ft_putnbr_pre_fd(va_arg(ptr, int));
	else if (ft == 'u')
	{
		temp = va_arg(ptr, unsigned int);
		i += ft_length_number_u(temp);
		ft_putnbr_fd_u(temp, 1);
	}
	else if ((ft == 'x') || (ft == 'X'))
		i += ft_put_hex(va_arg(ptr, unsigned long int), ft);
	else if (ft == 'p')
		i += ft_put_ptr(va_arg(ptr, unsigned long int));
	return (i);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		j;
	va_list	ptr;

	i = 0;
	j = 0;
	va_start(ptr, format);
	while (format[j])
	{
		if (format[j] == '%')
		{
			i += ft_printf_ft(ptr, format[j + 1]);
			j++;
		}
		else
			i += write(1, &format[j], 1);
		j++;
	}
	va_end(ptr);
	return (i);
}
