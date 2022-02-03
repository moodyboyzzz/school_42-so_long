/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:58:45 by ctommy            #+#    #+#             */
/*   Updated: 2022/02/02 12:58:46 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_check_collectable(t_game *game)
{
	if (game->map->map[game->player->y][game->player->x] == 'C')
	{
		game->player->collect += 1;
		game->map->map[game->player->y][game->player->x] = '0';
		if (game->player->collect == game->map->collect_max)
			game->player->exit_done = 1;
	}
}

void	ft_check_exit(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_exit(3, "Exit\n", game);
	else if (game->map->map[game->player->y][game->player->x] == 'E'
		&& game->player->exit_done == 1)
		ft_exit(3, "You won!\n", game);
}

void	ft_check_die(t_game *game)
{
	if (game->map->map[game->player->y][game->player->x] == 'V')
		ft_exit(3, "You lose...\n", game);
}
