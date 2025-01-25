/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:54:57 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/25 08:40:32 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

# define ESCAPE 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define MAX_WIDTH 204
# define MAX_HEIGHT 35

typedef struct s_game
{
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
	int		end;

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
void	free_map(char **map);
void	check_access(t_game *game);
void	set_dim(t_game *game, int i, int j);
void	check_for_new_line(char *copy);
void	check_extension(char *av);

#endif