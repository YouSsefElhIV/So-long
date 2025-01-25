/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 22:56:32 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/25 08:46:59 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	if (game->x - 1 < 0 || game->map[game->x - 1][game->y] == '1'
		|| (game->overall_food > 0 && game->map[game-> x - 1][game->y] == 'E'))
		return (0);
	game->map[game->x][game->y] = '0';
	game->x = game->x - 1;
	if (game->map[game->x][game->y] == 'C')
		game->food_eaten++;
	if (game->overall_food == 0 && game->map[game->x][game->y] == 'E')
		game->end = 1;
	game->map[game->x][game->y] = 'P';
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/Pac-Man/pac_up3.xpm", &game->x, &game->y);
	if (!game->player_img)
	{
		ft_printf("Error\nRendering Issue\n");
		exit (1);
	}
	return (1);
}

int	move_down(t_game *game)
{
	if (game->x + 1 > game->height || game->map[game->x + 1][game->y] == '1'
		|| (game->overall_food > 0 && game->map[game->x + 1][game->y] == 'E'))
		return (0);
	game->map[game->x][game->y] = '0';
	game->x = game->x + 1;
	if (game->map[game->x][game->y] == 'C')
		game->food_eaten++;
	if (game->overall_food == 0 && game->map[game->x][game->y] == 'E')
		game->end = 1;
	game->map[game->x][game->y] = 'P';
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/Pac-Man/pac_down3.xpm", &game->x, &game->y);
	if (!game->player_img)
	{
		ft_printf("Error\nRendering Issue\n");
		exit (1);
	}
	return (1);
}

int	move_right(t_game *game)
{
	if (game->y + 1 > game->width || game->map[game->x][game->y + 1] == '1'
		|| (game->overall_food > 0 && game->map[game->x][game->y + 1] == 'E'))
		return (0);
	game->map[game->x][game->y] = '0';
	game->y = game->y + 1;
	if (game->map[game->x][game->y] == 'C')
		game->food_eaten++;
	if (game->overall_food == 0 && game->map[game->x][game->y] == 'E')
		game->end = 1;
	game->map[game->x][game->y] = 'P';
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/Pac-Man/pac_right3.xpm", &game->x, &game->y);
	if (!game->player_img)
	{
		ft_printf("Error\nRendering Issue\n");
		exit (1);
	}
	return (1);
}

int	move_left(t_game *game)
{
	if (game->y - 1 < 0 || game->map[game->x][game->y - 1] == '1'
		|| (game->overall_food > 0 && game->map[game->x][game->y - 1] == 'E'))
		return (0);
	game->map[game->x][game->y] = '0';
	game->y = game->y - 1;
	if (game->map[game->x][game->y] == 'C')
		game->food_eaten++;
	if (game->overall_food == 0 && game->map[game->x][game->y] == 'E')
		game->end = 1;
	game->map[game->x][game->y] = 'P';
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/Pac-Man/pac_left3.xpm", &game->x, &game->y);
	if (!game->player_img)
	{
		ft_printf("Error\nRendering Issue\n");
		exit (1);
	}
	return (1);
}
