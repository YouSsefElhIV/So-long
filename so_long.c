/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:54:38 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/25 08:51:24 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(void)
{
	exit(0);
}

int	key_count(int keycode, t_game *game)
{
	static int	count;
	int			ok_move;

	ok_move = 0;
	if (keycode == ESCAPE)
		exit(0);
	if (keycode == UP)
		ok_move = move_up(game);
	else if (keycode == DOWN)
		ok_move = move_down(game);
	else if (keycode == RIGHT)
		ok_move = move_right(game);
	else if (keycode == LEFT)
		ok_move = move_left(game);
	if (ok_move == 1)
	{
		ft_printf("move count: %i\n", ++count);
		if (game->end == 1)
			exit(0);
		put_images_in_game(game);
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	check_imgs(t_game *game)
{
	int	i;
	int	j;
	int	flag;

	game->player_img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/Pac-Man/pac_down3.xpm", &i, &j);
	if (!game->player_img)
		flag = 1;
	game->player_img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/Pac-Man/pac_up3.xpm", &i, &j);
	if (!game->player_img)
		flag = 1;
	game->player_img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/Pac-Man/pac_right3.xpm", &i, &j);
	if (!game->player_img)
		flag = 1;
	game->player_img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/Pac-Man/pac_left3.xpm", &i, &j);
	if (!game->player_img)
		flag = 1;
	if (flag)
	{
		1 && (free_map(game->map), ft_printf("Error\nRendering issue\n"));
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_game		game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac == 2)
	{
		check_map(av, &game);
		game.mlx = mlx_init();
		if (game.mlx == NULL)
			return (free_map(game.map), exit (1), 1);
		game.mlx_window = mlx_new_window(game.mlx, (game.width) * 40, \
			(game.height) * 40, "so_long");
		if (game.mlx_window == NULL)
		{
			free_map(game.map);
			exit (1);
		}
		check_imgs(&game);
		initialize_images(&game);
		mlx_hook(game.mlx_window, 17, 0, exit_window, &game);
		mlx_key_hook(game.mlx_window, key_count, &game);
		mlx_loop(game.mlx);
		mlx_clear_window(game.mlx, game.mlx_window);
		free_map(game.map);
		free(game.mlx);
	}
}
