/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:22:38 by itorres-          #+#    #+#             */
/*   Updated: 2022/09/27 13:55:37 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x, int y)
{
	game->map[game ->player_pos_y][game ->player_pos_x] = '0';
	game->player_pos_x = game->player_pos_x + x;
	game->player_pos_y = game->player_pos_y + y;
	++game->marcador;
}

void	check_move_up(t_game *game)
{
	if (game->map[game ->player_pos_y - 1][game ->player_pos_x] != '1')
	{
		if (game->map[game ->player_pos_y - 1][game ->player_pos_x] == '0')
			move_player(game, 0, -1);
		if (game->map[game ->player_pos_y - 1][game ->player_pos_x] == 'C')
		{
			move_player(game, 0, -1);
			game->coins_count--;
		}	
		if ((game->map[game ->player_pos_y - 1][game ->player_pos_x] == 'E')
			&& (game->coins_count == 0))
			finish(game, 1);
		if ((game->map[game ->player_pos_y - 1][game ->player_pos_x] == 'E')
			&& (game->coins_count > 0))
				game->map[game ->player_pos_y][game ->player_pos_x] = 'P';
		imprimir_mapa(game);
	}
}

void	check_move_down(t_game *game)
{
	if (game->map[game ->player_pos_y + 1][game ->player_pos_x] != '1')
	{
		if (game->map[game ->player_pos_y + 1][game ->player_pos_x] == '0')
			move_player(game, 0, 1);
		if (game->map[game ->player_pos_y + 1][game ->player_pos_x] == 'C')
		{
			move_player(game, 0, 1);
			game->coins_count--;
		}
		if ((game->map[game ->player_pos_y + 1][game ->player_pos_x] == 'E')
			&& (game->coins_count == 0))
			finish(game, 1);
		if ((game->map[game ->player_pos_y + 1][game ->player_pos_x] == 'E')
			&& (game->coins_count > 0))
				game->map[game ->player_pos_y][game ->player_pos_x] = 'P';
		imprimir_mapa(game);
	}
}

void	check_move_left(t_game *game)
{
	if (game->map[game ->player_pos_y][game ->player_pos_x - 1] != '1')
	{
		if (game->map[game ->player_pos_y][game ->player_pos_x - 1] == '0')
			move_player(game, -1, 0);
		if (game->map[game ->player_pos_y][game ->player_pos_x - 1] == 'C')
		{
			game->coins_count--;
			move_player(game, -1, 0);
		}
		if ((game->map[game ->player_pos_y][game ->player_pos_x - 1] == 'E')
			&& (game->coins_count == 0))
			finish(game, 1);
		if ((game->map[game ->player_pos_y][game ->player_pos_x - 1] == 'E')
			&& (game->coins_count > 0))
				game->map[game ->player_pos_y][game ->player_pos_x] = 'P';
		imprimir_mapa(game);
	}
}

void	check_move_right(t_game *game)
{
	if (game->map[game ->player_pos_y][game ->player_pos_x + 1] != '1')
	{
		if (game->map[game ->player_pos_y][game ->player_pos_x + 1] == '0')
			move_player(game, 1, 0);
		if (game->map[game ->player_pos_y][game ->player_pos_x + 1] == 'C')
		{
			game->coins_count--;
			move_player(game, 1, 0);
		}
		if ((game->map[game ->player_pos_y][game ->player_pos_x + 1] == 'E')
			&& (game->coins_count == 0))
			finish(game, 1);
		if ((game->map[game ->player_pos_y][game ->player_pos_x + 1] == 'E')
			&& (game->coins_count > 0))
				game->map[game ->player_pos_y][game ->player_pos_x] = 'P';
		imprimir_mapa(game);
	}
}
