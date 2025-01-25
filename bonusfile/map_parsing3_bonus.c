/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:37:42 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/25 09:53:56 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_dim(t_game *game, int i, int j)
{
	game->height = i - 1;
	game->width = j;
	if (game->height >= MAX_HEIGHT || game->width > MAX_WIDTH \
	|| game->height + 1 == game->width)
	{
		write(2, "Error\nMap\n", 10);
		exit(1);
	}
}

void	check_for_new_line(char *copy)
{
	int	i;

	i = 0;
	while (copy[i])
		i++;
	if (copy[i - 1] == '\n')
	{
		write(2, "Error\nMap\n", 10);
		exit (1);
	}
}

void	check_extension(char *av)
{
	char	*dot_position;

	dot_position = ft_strrchr(av, '.');
	if (dot_position == NULL || ft_strlen(dot_position) != 4 \
	|| ft_strncmp(dot_position, ".ber", 4) != 0)
	{
		write(1, "Error\nMap\n", 10);
		exit(1);
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
		1 && (free_map(game->map), write(1, "Error\nRendering issue\n", 23));
		exit (1);
	}
}

void	put_str_to_screen(t_game *game, char *count_str)
{
	mlx_string_put(game->mlx, game->mlx_window, 30, \
	game->height * 40, 0x9DFFD, count_str);
}
