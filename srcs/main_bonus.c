/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:58:59 by ctommy            #+#    #+#             */
/*   Updated: 2022/02/02 12:59:00 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_check_arg(int argc, char *map_file)
{
	int	fd;
	int	len;

	if (argc != 2)
		ft_exit(0, "Error\nOnly 1 argument will be considered\n",
			NULL);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_exit(0, "Error\nCan't open map or file with that name "
			"does not exist\n", NULL);
	close(fd);
	len = ft_strlen(map_file);
	if ((map_file[len - 1] == 'r') && (map_file[len - 2] == 'e')
		&& (map_file[len - 3] == 'b') && (map_file[len - 4] == '.')
		&& (len >= 5))
		return ;
	else
		ft_exit(0, "Error\nWrong file name\n", NULL);
}

static int	ft_close(t_game *game)
{
	ft_exit(3, "Exit\n", game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_check_arg(argc, argv[1]);
	game = ft_init();
	ft_map_info(game, argv[1]);
	ft_map_check_params(game, argv[1]);
	ft_create_map(game, argv[1]);
	ft_init_player(game);
	game->mlx->mlx_ptr = mlx_init();
	game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr, game->map->width
			* SCALE, game->map->height * SCALE, "so_long");
	ft_init_img(game);
	mlx_key_hook(game->mlx->win_ptr, ft_key_control, game);
	mlx_hook(game->mlx->win_ptr, 17, 0, ft_close, game);
	mlx_loop_hook(game->mlx->mlx_ptr, ft_render_loop, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
