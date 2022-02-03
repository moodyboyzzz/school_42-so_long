/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:58:54 by ctommy            #+#    #+#             */
/*   Updated: 2022/02/02 12:58:55 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_game	*ft_init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_exit(1, "Error\nAllocation memory error\n", game);
	game->map = (t_map *)malloc(sizeof(t_map));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	game->wall = (t_img *)malloc(sizeof(t_img));
	game->background = (t_img *)malloc(sizeof(t_img));
	game->exit_0 = (t_img *)malloc(sizeof(t_img));
	game->exit_1 = (t_img *)malloc(sizeof(t_img));
	game->key = (t_img *)malloc(sizeof(t_img) * 12);
	game->player->player = (t_img *)malloc(sizeof(t_img));
	game->enemy = (t_img *)malloc(sizeof(t_img));
	if (!(game->map) || !(game->mlx) || !(game->wall) || !(game->player)
		|| !(game->background) || !(game->exit_0) || !(game->key)
		|| !(game->player->player) || !(game->exit_1) || !(game->enemy))
		ft_exit(1, "Error\nAllocation memory error\n", game);
	return (game);
}

void	ft_init_player(t_game *game)
{
	game->player->collect = 0;
	game->player->steps = 0;
	game->player->exit_done = 0;
}

void	ft_init_file(t_game *game, t_img *img, char *path)
{
	img->width = 0;
	img->height = 0;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, path,
			&img->width, &img->height);
}

void	ft_init_img(t_game *game)
{
	ft_init_file(game, game->background, BACKGROUND);
	ft_init_file(game, game->wall, WALL);
	ft_init_file(game, &game->key[0], KEY0);
	ft_init_file(game, &game->key[1], KEY1);
	ft_init_file(game, &game->key[2], KEY2);
	ft_init_file(game, &game->key[3], KEY3);
	ft_init_file(game, &game->key[4], KEY4);
	ft_init_file(game, &game->key[5], KEY5);
	ft_init_file(game, &game->key[6], KEY6);
	ft_init_file(game, &game->key[7], KEY7);
	ft_init_file(game, &game->key[8], KEY8);
	ft_init_file(game, &game->key[9], KEY9);
	ft_init_file(game, &game->key[10], KEY10);
	ft_init_file(game, &game->key[11], KEY11);
	ft_init_file(game, game->player->player, PLAYER);
	ft_init_file(game, game->exit_0, EXIT_0);
	ft_init_file(game, game->exit_1, EXIT_1);
	ft_init_file(game, game->enemy, ENEMY);
}
