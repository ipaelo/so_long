/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:56:42 by itorres-          #+#    #+#             */
/*   Updated: 2022/09/27 14:26:06 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		finish(game, 0);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		check_move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		check_move_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		check_move_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		check_move_right(game);
}

void	close_hook(void *param)
{
	t_game	*game;

	game = param;
	finish(game, 0);
}

void	init_game_vars(t_game *game)
{
	game->width = 0;
	game->w_height = 0;
	game->marcador = 0;
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->coins_count = 0;
	game->len = 0;
	game->a_height = 1;
	game->i = -1;
	game->j = -1;
	game->mlx = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\n");
		ft_printf("Incorrect arguments\n");
		return (0);
	}
	if (check_ext(argv[1]))
		exit(EXIT_FAILURE);
	init_game_vars(&game);
	read_map(&game, argv[1]);
	start_player_coins(&game);
	check_map(&game);
	game.mlx = mlx_init(game.width, game.w_height, "Old West", true);
	if (!game.mlx)
		exit(EXIT_FAILURE);
	load_textures_images(&game);
	imprimir_mapa(&game);
	mlx_key_hook(game.mlx, my_keyhook, &game);
	mlx_close_hook(game.mlx, close_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
