/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:55:13 by itorres-          #+#    #+#             */
/*   Updated: 2022/09/27 12:30:02 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_get_line(char *str)
{
	char	*clean_str;
	int		count;
	int		filler;

	if (!str)
		return (0);
	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	clean_str = (char *)malloc(sizeof(char) * (count + 2));
	if (!(clean_str))
		return (0);
	filler = 0;
	while (str[filler] != '\0')
	{
		clean_str[filler] = str[filler];
		filler++;
		if (str[filler - 1] == '\n')
			break ;
	}
	clean_str[filler] = '\0';
	return (clean_str);
}

char	*ft_read_file(int fd, char *temp_buff, char *remain)
{
	char	*temp;
	int		read_ok;

	read_ok = 1;
	while (read_ok)
	{
		read_ok = read(fd, temp_buff, BUFFER_SIZE);
		if (read_ok == -1)
			return (0);
		else if (read_ok == 0)
			break ;
		temp_buff[read_ok] = '\0';
		if (!remain)
			remain = ft_strdup("");
		temp = remain;
		remain = ft_strjoin2(temp, temp_buff);
		if (!remain)
			return (0);
		if (ft_strchr(temp_buff, '\n'))
			break ;
	}
	return (remain);
}

char	*ft_clean_remain(char *str)
{
	char	*clean_str;
	int		count;
	int		filler;

	if (!str)
		return (0);
	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	if (ft_strlen(str) == 0 || ft_strlen(str) - (count) == 0)
		return (0);
	clean_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - count));
	if (!(clean_str))
		return (0);
	filler = 0;
	count++;
	while (str[filler + count])
	{
		clean_str[filler] = str[filler + count];
		filler++;
	}
	clean_str[filler] = '\0';
	return (clean_str);
}

char	*get_next_line(int fd)
{
	static char	*remain[256];
	char		*temp;
	char		*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	str = ft_read_file(fd, temp, remain[fd]);
	free(temp);
	if (!str || str[0] == '\0')
	{
		free(remain[fd]);
		remain[fd] = 0;
		return (0);
	}
	line = ft_get_line(str);
	remain[fd] = ft_clean_remain(str);
	free(str);
	return (line);
}
