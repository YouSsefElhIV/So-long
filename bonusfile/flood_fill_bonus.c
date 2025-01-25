/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:36:43 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/25 18:45:42 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill2(char **tab, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= 35 || col >= 204)
		return ;
	if (tab[row][col] == '1' || tab[row][col] == 'F')
		return ;
	tab[row][col] = 'F';
	fill2(tab, target, row -1, col);
	fill2(tab, target, row +1, col);
	fill2(tab, target, row, col - 1);
	fill2(tab, target, row, col + 1);
}

void	flood_fill2(char **tab, t_game *game)
{
	char	target;
	int		j;
	int		i;

	target = tab[game->x][game->y];
	i = 0;
	fill2(tab, target, game->x, game->y);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C' && tab[i][j] != 'F')
			{
				write(2, "ERROR!\nNO ACCESS TO COIN\n", 25);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	flood_fill_for_coins(t_game *game)
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
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E')
				map[i][j] = '1';
			j++;
		}
		1 && (map[i][j] = '\0', i++);
	}
	map[i] = NULL;
	flood_fill2(map, game);
	free_map(map);
}
