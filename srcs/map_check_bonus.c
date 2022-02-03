/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:59:02 by ctommy            #+#    #+#             */
/*   Updated: 2022/02/02 12:59:03 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	ft_check_param(char flag, char *map_file)
{
	int		fd;
	int		param;
	char	c[1];

	param = 0;
	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
		if (c[0] == flag)
			param++;
	close(fd);
	return (param);
}

static int	ft_check_symbols(char *map_file)
{
	int		fd;
	char	c[1];

	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
	{
		if (c[0] != '0' && c[0] != '1' && c[0] != 'C' && c[0] != 'V'
			&& c[0] != 'E' && c[0] != 'P' && c[0] != '\n')
		{
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (1);
}

void	ft_map_check_params(t_game *game, char *map_file)
{
	game->map->empty_space = ft_check_param('0', map_file);
	game->map->wall = ft_check_param('1', map_file);
	game->map->collect_max = ft_check_param('C', map_file);
	game->map->map_exit = ft_check_param('E', map_file);
	game->map->player = ft_check_param('P', map_file);
	game->map->enemy = ft_check_param('V', map_file);
	if ((game->map->empty_space > 0) && (game->map->wall > 1)
		&& (game->map->collect_max > 0) && (game->map->map_exit > 0)
		&& (game->map->player == 1) && ft_check_symbols(map_file)
		&& (game->map->enemy > 0))
		return ;
	ft_exit(1, "Error\nInvalid map or symbols on the map\n", game);
}
