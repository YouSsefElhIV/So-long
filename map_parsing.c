/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:20:28 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/24 22:51:26 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *map_name)
{
	int		fd;
	char	*line;
	char	*map;
	char	**copy_of_the_map;
	char	*tmp;

	1 && (map = NULL, fd = open(map_name, O_RDONLY));
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_strjoin(map, line);
		free(map);
		map = tmp;
		if (map[0] == '\n')
			return (close(fd), free(map), NULL);
		free(line);
		line = get_next_line(fd);
	}
	if (!map)
		return (close(fd), NULL);
	check_for_new_line(map);
	copy_of_the_map = ft_split(map, '\n');
	return (free(map), close(fd), copy_of_the_map);
}

int	sides_check(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i <= height)
	{
		if (map[i][width - 1] != '1' || map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	checking_walls(char **map, t_game *game)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != '\0')
			return (0);
		j++;
	}
	j = 0;
	while (map[game->height][j])
	{
		if (map[game->height][j] != '1' && map[game->height][j + 1] != '\0')
			return (0);
		j++;
	}
	return (sides_check(map, game->height, game->width));
}

void	set_dimention(char **map, t_game *game)
{
	int	i;
	int	j;
	int	old_j;

	1 && (i = 0, j = 0);
	if (!game || !map)
		return ;
	while (map[0][j])
		j++;
	old_j = j;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != old_j)
		{
			ft_printf("Error\nMap\n");
			exit(1);
		}
		old_j = j;
		i++;
	}
	set_dim(game, i, j);
}

int	check_map(char **av, t_game *game)
{
	int		i;

	i = 0;
	check_extension(av[1]);
	game->map = read_map(av[1]);
	set_dimention(game->map, game);
	if (game->map == NULL || game->map[1] == NULL)
	{
		ft_printf("Error\nMap\n");
		exit(1);
	}
	if (checking_walls(game->map, game) == 0)
	{
		ft_printf("Error\nMap\n");
		exit(1);
	}
	game->height = game->height + 1;
	checking_tools(game->map, game);
	check_access(game);
	return (0);
}
