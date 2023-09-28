/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:09:34 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/05 12:32:48 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*f_str;
	int		count;

	f_str = malloc (ft_strlen(s) + 1 * sizeof(char));
	if (f_str == NULL)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
	{
		f_str[count] = f(count, s[count]);
		count++;
	}
	f_str[count] = '\0';
	return (f_str);
}
