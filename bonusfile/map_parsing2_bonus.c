/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:17:53 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/24 22:11:29 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	helper_for_checking_tool(t_game *game, char **map, int i, int j)
{
	if (map[i][j] == 'E')
		game->exit++;
	else if (map[i][j] == 'P')
	{
		game->x = i;
		game->y = j;
		game->player++;
	}
	else if (map[i][j] == 'C')
		game->food = 1;
	else if (map[i][j] == '1')
		game->wall = 1;
	else if (map[i][j] == '0')
		game->path = 1;
	else if (map[i][j] == 'N')
		game->enemy = 1;
	else
	{
		write(2, "Error\nMap\n", 10);
		exit(1);
	}
}

void	checking_tools(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			helper_for_checking_tool(game, map, i, j);
			j++;
		}
		i++;
	}
	if (game->exit != 1 || game->player != 1 || game->path != 1
		|| game->wall != 1 || game->food != 1 || game->enemy != 1)
	{
		write(2, "Error\nMap\n", 10);
		exit(1);
	}
}

void	fill(char **tab, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= 35 || col >= 204)
		return ;
	if (tab[row][col] == '1' || tab[row][col] == 'F')
		return ;
	tab[row][col] = 'F';
	fill(tab, target, row -1, col);
	fill(tab, target, row +1, col);
	fill(tab, target, row, col - 1);
	fill(tab, target, row, col + 1);
}

void	flood_fill(char **tab, t_game *game)
{
	char	target;
	int		j;
	int		i;

	target = tab[game->x][game->y];
	i = 0;
	fill(tab, target, game->x, game->y);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'E' && tab[i][j] != 'F')
			{
				write(2, "ERROR!\nNO ACCESS TO EXIT\n", 25);
				exit (1);
			}
			j++;
		}
		i++;
	}
	flood_fill_for_coins(game);
}

void	check_access(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	1 && (i = 0, map = (char **)malloc(sizeof(char *) * (game->height + 1)));
	if (!map)
		exit (1);
	while (i < game->height)
	{
		j = 0;
		map[i] = (char *)malloc(sizeof(char) * (game->width + 1));
		if (!map[i])
			exit (1);
		while (j < game->width)
		{
			map[i][j] = game->map[i][j];
			if (game->map[i][j] == 'N')
				map[i][j] = '1';
			j++;
		}
		1 && (map[i][j] = '\0', i++);
	}
	map[i] = NULL;
	flood_fill(map, game);
	free_map(map);
}
