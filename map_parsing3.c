/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:43:39 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/25 09:53:33 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_dim(t_game *game, int i, int j)
{
	game->height = i - 1;
	game->width = j;
	if (game->height >= MAX_HEIGHT || game->width > MAX_WIDTH \
	|| game->height + 1 == game->width)
	{
		ft_printf("Error\nMap\n");
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
		ft_printf("Error\nMap\n");
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
		ft_printf("Error\nMap\n");
		exit(1);
	}
}
