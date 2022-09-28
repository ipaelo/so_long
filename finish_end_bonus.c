/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_end_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:52:38 by itorres-          #+#    #+#             */
/*   Updated: 2022/09/27 14:47:55 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_game(t_game *game)
{
	free_map(game->map);
}

void	finish(t_game *game, int win_lose)
{	
	if (win_lose == 1)
		ft_printf("YOU WIN!!");
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	free_game(game);
	exit(1);
}

void	file_error(int fd)
{
	if (fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("File don't load\n");
		exit(EXIT_FAILURE);
	}
}
