/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:18:09 by itorres-          #+#    #+#             */
/*   Updated: 2022/09/27 14:41:08 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

#define image_path_1 "assets/wall.png"
#define image_path_2 "assets/soil.png"
#define image_path_3 "assets/chest_close.png"
#define image_path_4 "assets/player.png"
#define image_path_5 "assets/chest_open.png"
#define image_path_6 "assets/coin.png"

typedef struct s_images
{	
	
	mlx_texture_t *g_text_1;
	mlx_texture_t *g_text_2;
	mlx_texture_t *g_text_3;
	mlx_texture_t *g_text_4;
	mlx_texture_t *g_text_5;
	mlx_texture_t *g_text_6;
	mlx_image_t	*g_img_wall;
	mlx_image_t	*g_img_soil;
	mlx_image_t	*g_img_chest_close;
	mlx_image_t	*g_img_player;
	mlx_image_t	*g_img_chest_open;
	mlx_image_t	*g_img_coin;

} 			t_images;


typedef struct s_game
{
	mlx_t		*mlx;
	void   		*window;
	char 		**map;
	t_images 	image;
	
	int 		width;
	int 		a_height;
	int 		w_height;
	int 		len;
	int 		player_pos_x;
	int			player_pos_y;
	int 		coins_count;
	int 		marcador;
	int 		i;
	int			j;
}				t_game;

void	check_columns(t_game *game);
void	check_valid_chars(t_game *game);
void	start_player_coins(t_game *game);
void	check_player(t_game *game);
void	check_exit(t_game *game);
void	check_walled(t_game *game);
void	check_map_rect(t_game *game);
void	check_map(t_game *game);
int		check_ext(char *str);
void	move_player(t_game *game, int x, int y);
void	check_move_up(t_game *game);
void	check_move_down(t_game *game);
void	check_move_left(t_game *game);
void	check_move_right(t_game *game);
void	load_textures_images(t_game *game);
void	print_chest(t_game *game);
void	print_player(t_game *game);
void	imprimir_mapa(t_game *game);
void	read_map(t_game *game, char *str);
void	free_map(char **map);
void	free_game(t_game *game);
void	finish(t_game *game, int win_lose);

#endif