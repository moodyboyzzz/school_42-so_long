/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:59:07 by ctommy            #+#    #+#             */
/*   Updated: 2022/02/02 12:59:08 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	ft_create_height(char *map_file)
{
	int		fd;
	int		height;
	char	c[1];

	height = 1;
	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
		if (c[0] == '\n')
			height++;
	close(fd);
	return (height);
}

static int	ft_create_width(char *map_file)
{
	int		fd;
	int		width;
	char	c[1];

	width = 0;
	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
	{
		if (c[0] == '\n')
			break ;
		width++;
	}
	close(fd);
	return (width);
}

static void	ft_is_rectangle(char *map_file, t_game *game)
{
	int		fd;
	int		i;
	char	c[1];

	i = 0;
	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
	{
		i++;
		if (c[0] == '\n')
		{
			i--;
			if (i != game->map->width)
			{
				close (fd);
				ft_exit(1, "Error\nThis map is not a rectangle\n",
					game);
			}
			i = 0;
		}
	}
	close (fd);
	if (i != game->map->width)
		ft_exit(1, "Error\nThis map is not a rectangle\n",
			game);
}

void	ft_map_info(t_game *game, char *map_file)
{
	game->map->height = ft_create_height(map_file);
	game->map->width = ft_create_width(map_file);
	ft_is_rectangle(map_file, game);
}
