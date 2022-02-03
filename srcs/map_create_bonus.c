/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:59:05 by ctommy            #+#    #+#             */
/*   Updated: 2022/02/02 12:59:06 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_check_wall(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->height)
	{
		if ((i == 0) || (i == game->map->height - 1))
		{
			j = -1;
			while (++j < game->map->width)
			{
				if (game->map->map[i][j] != '1')
					ft_exit(2, "Error\nHaven't wall in the top/lower line\n",
						game);
			}
		}
		else
		{
			if ((game->map->map[i][0] != '1')
			|| (game->map->map[i][game->map->width - 1] != '1'))
				ft_exit(2, "Error\nMissing a wall on the right or left\n",
					game);
		}
	}
}

static void	ft_check_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'P')
			{
				game->player->x = j;
				game->player->y = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_create_map(t_game *game, char *map_file)
{
	int		fd;
	int		i;
	int		tmp[1];

	i = 0;
	fd = open(map_file, O_RDONLY);
	game->map->map = (char **)malloc(sizeof(char *) * game->map->height);
	if (!(game->map->map))
		ft_exit(2, "Error\nMemory allocation for the map error\n", game);
	while (i < game->map->height)
	{
		game->map->map[i] = (char *)malloc(sizeof(char)
				* (game->map->width + 1));
		if (!(game->map->map[i]))
			ft_exit(2, "Error\nMemory allocation for the map error\n", game);
		read(fd, game->map->map[i], game->map->width);
		game->map->map[i][game->map->width] = '\0';
		i++;
		read(fd, tmp, 1);
	}
	close (fd);
	ft_check_wall(game);
	ft_check_player(game);
}
