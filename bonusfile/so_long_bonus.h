/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:17:27 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/25 08:51:47 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "get_next_line_bonus/get_next_line_bonus.h"

# define ESCAPE 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define MAX_WIDTH 204
# define MAX_HEIGHT 34

typedef struct s_game
{
	int		ghost_x;
	int		ghost_y;
	int		x;
	int		y;
	char	**map;
	int		width;
	int		height;
	int		player;
	int		food;
	int		path;
	int		exit;
	int		wall;
	int		overall_food;
	int		food_eaten;
	int		enemy;
	int		end;

	void	*enemy_img;
	void	*player_img;
	void	*food_img;
	void	*path_img;
	void	*exit_img;
	void	*wall_img;
	void	*mlx;
	void	*mlx_window;
}	t_game;

char	**read_map(char *map_name);
int		check_map(char **av, t_game *game);
void	checking_tools(char **map, t_game *game);
void	put_images_in_game(t_game *game);
void	initialize_images(t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_right(t_game *game);
int		move_left(t_game *game);
void	place_player(t_game *game, int height, int width);
void	check_access(t_game *game);
void	free_map(char **map);
void	set_dim(t_game *game, int i, int j);
void	check_for_new_line(char *copy);
void	check_extension(char *av);
void	check_imgs(t_game *game);
void	put_str_to_screen(t_game *game, char *count_str);
void	flood_fill_for_coins(t_game *game);

#endif
