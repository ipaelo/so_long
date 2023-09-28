/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:27:42 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/08 14:35:21 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	else if (len_s < len + start)
		len = len_s - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_memcpy(substr, &s[start], len);
	substr[len] = '\0';
	return (substr);
}
