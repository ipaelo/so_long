/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:30:00 by itorres-          #+#    #+#             */
/*   Updated: 2022/09/27 15:04:45 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures_images(t_game *game)
{
	game->image.g_text_1 = mlx_load_png(image_path_1);
	game->image.g_text_2 = mlx_load_png(image_path_2);
	game->image.g_text_3 = mlx_load_png(image_path_3);
	game->image.g_text_4 = mlx_load_png(image_path_4);
	game->image.g_text_5 = mlx_load_png(image_path_5);
	game->image.g_text_6 = mlx_load_png(image_path_6);
	game->image.g_img_wall = mlx_texture_to_image(game->mlx,
			game->image.g_text_1);
	game->image.g_img_soil = mlx_texture_to_image(game->mlx,
			game->image.g_text_2);
	game->image.g_img_chest_close = mlx_texture_to_image(game->mlx,
			game->image.g_text_3);
	game->image.g_img_player = mlx_texture_to_image(game->mlx,
			game->image.g_text_4);
	game->image.g_img_chest_open = mlx_texture_to_image(game->mlx,
			game->image.g_text_5);
	game->image.g_img_coin = mlx_texture_to_image(game->mlx,
			game->image.g_text_6);
}

void	print_chest(t_game *game)
{
	if (game->coins_count > 0)
		mlx_image_to_window(game->mlx,
			game->image.g_img_chest_close, game->i * 64, game->j * 64);
	else
		mlx_image_to_window(game->mlx,
			game->image.g_img_chest_open, game->i * 64, game->j * 64);
}

void	print_player(t_game *game)
{
	char	*s;

	mlx_image_to_window(game->mlx, game->image.g_img_player,
		game ->player_pos_x * 64, game ->player_pos_y * 64);
	mlx_put_string(game->mlx, "Pasos:", 10, 20);
	s = ft_itoa(game->marcador);
	mlx_put_string(game->mlx, s, 80, 20);
	free(s);
	mlx_put_string(game->mlx, "Monedas:", 150, 20);
	s = ft_itoa(game->coins_count);
	mlx_put_string(game->mlx, s, 240, 20);
	free(s);
}

void	imprimir_mapa(t_game *game)
{
	game->j = -1;
	while (game->map[++game->j])
	{
		game->i = -1;
		while (game->map[game->j][++game->i])
		{
			if (game->map[game->j][game->i] == '1')
				mlx_image_to_window(game->mlx, game->image.g_img_wall,
					game->i * 64, game->j * 64);
			if (game->map[game->j][game->i] == 'C')
				mlx_image_to_window(game->mlx, game->image.g_img_coin,
					game->i * 64, game->j * 64);
			if (game->map[game->j][game->i] == 'E')
				print_chest(game);
			if (game->map[game->j][game->i] == 'P')
				mlx_image_to_window(game->mlx, game->image.g_img_player,
					game->i * 64, game->j * 64);
			if (game->map[game->j][game->i] == '0')
				mlx_image_to_window(game->mlx, game->image.g_img_soil,
					game->i * 64, game->j * 64);
		}
	}
	print_player(game);
}

void	read_map(t_game *game, char *str)
{
	char	*line;
	char	*tmpline;
	int		fd;

	fd = 0;
	tmpline = ft_strdup("");
	fd = open(str, O_RDONLY);
	file_error(fd);
	line = get_next_line(fd);
	if (line == NULL)
		exit(EXIT_FAILURE);
	game->len = ft_strlen(line);
	while (line)
	{
		tmpline = ft_strjoin2(tmpline, line);
		free(line);
		line = get_next_line(fd);
		game->a_height++;
	}
	game->map = ft_split(tmpline, '\n');
	free(tmpline);
	close(fd);
	game->width = (game->len - 1) * 64;
	game->w_height = (game->a_height - 1) * 64;
}
