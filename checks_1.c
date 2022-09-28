/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:24:11 by itorres-          #+#    #+#             */
/*   Updated: 2022/09/27 15:03:47 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walled(t_game *game)
{
	game->j = -1;
	while (game->map[++game->j])
	{
		game->i = -1;
		while (game->map[game->j][++game->i])
		{
			if ((game->map[0][game->i] != '1') ||
			(game->map[game->a_height - 2][game->i] != '1'))
			{
				ft_printf("Error\n");
				ft_printf("Walls aren't fulled\n");
				finish(game, 0);
			}
			if ((game->map[game->j][0] != '1') ||
			(game->map[game->j][game->len - 2] != '1'))
			{
				ft_printf("Error\n");
				ft_printf("Walls aren't fulled\n");
				finish(game, 0);
			}
		}
	}
}

void	check_map_rect(t_game *game)
{
	if (game->a_height == game->len)
	{
		ft_printf("Error\n");
		ft_printf("Map is not rectangular\n");
		finish(game, 0);
	}
}

void	check_map(t_game *game)
{
	check_columns(game);
	check_valid_chars(game);
	check_map_rect(game);
	check_walled(game);
	check_player(game);
	check_exit(game);
	if (game->coins_count < 1)
	{
		ft_printf("Error\n");
		ft_printf("Need at least 1 collectable\n");
		finish(game, 0);
	}
}

int	check_ext(char *str)
{
	if (str[ft_strlen(str) - 4] != '.' || str[ft_strlen(str) - 3] != 'b'
		|| str[ft_strlen(str) - 2] != 'e' || str[ft_strlen(str) - 1] != 'r')
	{
		ft_printf("Error\n");
		ft_printf("Map must be .ber\n");
		return (1);
	}
	return (0);
}
