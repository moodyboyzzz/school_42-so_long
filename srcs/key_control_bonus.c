/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:58:56 by ctommy            #+#    #+#             */
/*   Updated: 2022/02/02 12:58:57 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_key_wasd_utils(t_game *game, int *x_y, int sign)
{
	if (sign == 1)
		*x_y += 1;
	else
		*x_y -= 1;
	game->player->steps++;
}

static void	ft_key_wasd(int keycode, t_game *game)
{
	if ((keycode == 13) && (game->map->map[game->player->y - 1][game->player->x]
		!= '1'))
		ft_key_wasd_utils(game, &game->player->y, 0);
	else if ((keycode == 1) && (game->map->map[game->player->y
				+ 1][game->player->x] != '1'))
		ft_key_wasd_utils(game, &game->player->y, 1);
	else if ((keycode == 2) && (game->map->map[game->player->y]
			[game->player->x + 1] != '1'))
		ft_key_wasd_utils(game, &game->player->x, 1);
	else if ((keycode == 0) && (game->map->map[game->player->y]
			[game->player->x - 1] != '1'))
		ft_key_wasd_utils(game, &game->player->x, 0);
}

int	ft_key_control(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		ft_key_wasd(keycode, game);
	ft_check_collectable(game);
	ft_check_die(game);
	ft_check_exit(keycode, game);
	return (0);
}
