/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_images_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:17:36 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/22 20:28:12 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_images(t_game *game)
{
	int	i;
	int	j;

	game->wall_img = mlx_xpm_file_to_image(game->mlx, \
	"./textures/Other/Walls/wall1.xpm", &i, &j);
	game->player_img = mlx_xpm_file_to_image(game->mlx, \
	"./textures/Pac-Man/pac_closed.xpm", &i, &j);
	game->food_img = mlx_xpm_file_to_image(game->mlx, \
	"./textures/Other/Pacdots/pacdot_food1.xpm", &i, &j);
	game->path_img = mlx_xpm_file_to_image(game->mlx, \
	"./textures/Other/Walls/black.xpm", &i, &j);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, \
	"./textures/Other/Portal/portal1.xpm", &i, &j);
	game->enemy_img = mlx_xpm_file_to_image(game->mlx, \
	"./textures/Ghosts/ghost_downR1.xpm", &i, &j);
	if (!game->wall_img || !game->player_img || !game->food_img \
	|| !game->path_img || !game->exit_img || !game->enemy_img)
	{
		free_map(game->map);
		write(2, "Error\nRendering issue\n", 22);
		exit (1);
	}
	put_images_in_game(game);
}

void	place_player(t_game *game, int height, int width)
{
	game->x = height;
	game->y = width;
	mlx_put_image_to_window(game->mlx,
		game->mlx_window, game->player_img, width * 40, height * 40);
}

void	placing(t_game *game, int height, int width, void *which)
{
	mlx_put_image_to_window(game->mlx,
		game->mlx_window, which, width * 40, height * 40);
	if (which == game->food_img)
		game->overall_food++;
}

void	place_ghost(t_game *game, int height, int width)
{
	game->ghost_x = height;
	game->ghost_y = width;
	mlx_put_image_to_window(game->mlx,
		game->mlx_window, game->enemy_img, width * 40, height * 40);
}

void	put_images_in_game(t_game *game)
{
	int	i;
	int	j;

	1 && (i = 0, game->overall_food = 0);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
				placing(game, i, j, game->wall_img);
			else if (game->map[i][j] == '0')
				placing(game, i, j, game->path_img);
			else if (game->map[i][j] == 'P')
				place_player(game, i, j);
			else if (game->map[i][j] == 'E')
				placing(game, i, j, game->exit_img);
			else if (game->map[i][j] == 'C')
				placing(game, i, j, game->food_img);
			else if (game->map[i][j] == 'N')
				place_ghost(game, i, j);
			j++;
		}
		i++;
	}
}
