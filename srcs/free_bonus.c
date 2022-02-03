/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:58:51 by ctommy            #+#    #+#             */
/*   Updated: 2022/02/02 12:58:52 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		if (game->map->map[i])
			free(game->map->map[i]);
		i++;
	}
	if (game->map->map)
		free(game->map->map);
}

static void	ft_init_free(t_game *game, int malloc)
{
	if (game->enemy)
		free(game->enemy);
	if (game->player->player)
		free (game->player->player);
	if (game->player)
		free (game->player);
	if (game->key)
		free (game->key);
	if (game->exit_1)
		free (game->exit_1);
	if (game->exit_0)
		free (game->exit_0);
	if (game->background)
		free (game->background);
	if (game->wall)
		free (game->wall);
	if (malloc)
		ft_free_map(game);
	if (game->mlx)
		free (game->mlx);
	if (game->map)
		free (game->map);
	free (game);
}

static void	ft_free_malloc(t_game *game)
{
	int	i;

	i = 0;
	if (game->wall->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->wall->img_ptr);
	if (game->background->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->background->img_ptr);
	if (game->exit_0->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->exit_0->img_ptr);
	if (game->exit_1->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->exit_1->img_ptr);
	if (game->player->player->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->player->player->img_ptr);
	if (game->enemy->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->enemy->img_ptr);
	while (i < 12)
	{
		if (game->key[i].img_ptr)
			mlx_destroy_image(game->mlx->mlx_ptr, game->key[i].img_ptr);
		i++;
	}
	if (game->mlx->win_ptr)
		mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
	ft_init_free(game, 1);
}

void	ft_exit(int malloc, char *str, t_game *game)
{
	printf("%s\n", str);
	if (malloc == 1)
		ft_init_free(game, 0);
	else if (malloc == 2)
		ft_init_free(game, 1);
	else if (malloc == 3)
		ft_free_malloc(game);
	exit(EXIT_FAILURE);
}
