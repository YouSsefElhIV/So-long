/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:17:22 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/25 09:58:42 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_ghost(t_game *game)
{
	static int	frame_counter;
	static int	up;

	if (frame_counter % 10 == 0)
	{
		if (up == 0)
		{
			game->enemy_img = mlx_xpm_file_to_image(game->mlx, \
"./textures/Ghosts/ghost_upR1.xpm", &(game->ghost_y), &(game->ghost_y));
			up = 1;
		}
		else
		{
			game->enemy_img = mlx_xpm_file_to_image(game->mlx, \
"./textures/Ghosts/ghost_downR1.xpm", &(game->ghost_y), &(game->ghost_y));
			up = 0;
		}
	}
	frame_counter++;
	if (!game->enemy_img)
	{
		write(1, "Error\nRendering Issue\n", 23);
		exit (1);
	}
	put_images_in_game(game);
}

int	exit_window(void)
{
	exit(0);
}

int	key_count(int keycode, t_game *game)
{
	static int	count;
	int			ok_move;
	char		count_str[50];

	ok_move = 0;
	if (keycode == ESCAPE)
		exit (0);
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
		mlx_clear_window(game->mlx, game->mlx_window);
		sprintf(count_str, "Move count: %i", ++count);
		if (game->end == 1)
			exit(0);
		put_str_to_screen(game, count_str);
		put_images_in_game(game);
	}
	return (1);
}

int	update_frame(t_game *game)
{
	move_ghost(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game		game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac == 2)
	{
		check_map(av, &game);
		game.mlx_window = mlx_new_window(game.mlx, (game.width) * 40, \
		(game.height + 1) * 40, "so_long");
		if (game.mlx_window == NULL)
		{
			mlx_clear_window(game.mlx, game.mlx_window);
			free(game.mlx);
			exit (1);
		}
		check_imgs(&game);
		initialize_images(&game);
		mlx_hook(game.mlx_window, 17, 0, exit_window, &game);
		mlx_string_put(game.mlx, game.mlx_window, 40, game.height * 40, \
		0xFF0000, "press w/s/a/d");
		mlx_key_hook(game.mlx_window, key_count, &game);
		mlx_loop_hook(game.mlx, update_frame, &game);
		mlx_loop(game.mlx);
		mlx_clear_window(game.mlx, game.mlx_window);
		free(game.mlx);
	}
}
