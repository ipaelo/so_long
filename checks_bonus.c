/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:24:11 by itorres-          #+#    #+#             */
/*   Updated: 2022/09/27 14:56:51 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_columns(t_game *game)
{
	game->j = -1;
	while (game->map[++game->j])
	{
		if ((ft_strlen(game->map[game->j]) != game->len - 1))
		{
			ft_printf("Error\n");
			ft_printf("Columns lengths wrong!\n");
			finish(game, 0);
		}
	}
}

void	check_valid_chars(t_game *game)
{
	int	p;

	p = 0;
	game->j = -1;
	while (game->map[++game->j])
	{
		game->i = -1;
		while (game->map[game->j][++game->i])
		{
			if (ft_strchr("1P0EC", game->map[game->j][game->i]) == NULL)
				p++;
		}
	}
	if (p > 0)
	{
		ft_printf("Error\n");
		ft_printf("Map character wrong!\n");
		finish(game, 0);
	}
}

void	start_player_coins(t_game *game)
{
	game->j = -1;
	while (game->map[++game->j])
	{
		game->i = -1;
		while (game->map[game->j][++game->i])
		{
			if (game->map[game->j][game->i] == 'P')
			{
				game ->player_pos_x = game->i;
				game ->player_pos_y = game->j;
			}
			if (game->map[game->j][game->i] == 'C')
				game->coins_count++;
		}
	}
}

void	check_player(t_game *game)
{
	int	p;

	p = 0;
	game->j = -1;
	while (game->map[++game->j])
	{
		game->i = -1;
		while (game->map[game->j][++game->i])
		{
			if (game->map[game->j][game->i] == 'P')
				p++;
		}
	}
	if (p < 1)
	{
		ft_printf("Error\n");
		ft_printf("1 player needed\n");
		finish(game, 0);
	}
}

void	check_exit(t_game *game)
{
	int	p;

	p = 0;
	game->j = -1;
	while (game->map[++game->j])
	{
		game->i = -1;
		while (game->map[game->j][++game->i])
		{
			if (game->map[game->j][game->i] == 'E')
				p++;
		}
	}
	if (p < 1)
	{
		ft_printf("Error\n");
		ft_printf("1 exit needed\n");
		finish(game, 0);
	}
}
