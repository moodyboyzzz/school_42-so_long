/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:59:13 by ctommy            #+#    #+#             */
/*   Updated: 2022/02/02 12:59:14 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include "../Libft/libft.h"

# define SCALE 32
# define BACKGROUND "./IMG/background.xpm"
# define WALL "./IMG/wall.xpm"
# define KEY0 "./IMG/key/key0.xpm"
# define KEY1 "./IMG/key/key1.xpm"
# define KEY2 "./IMG/key/key2.xpm"
# define KEY3 "./IMG/key/key3.xpm"
# define KEY4 "./IMG/key/key4.xpm"
# define KEY5 "./IMG/key/key5.xpm"
# define KEY6 "./IMG/key/key6.xpm"
# define KEY7 "./IMG/key/key7.xpm"
# define KEY8 "./IMG/key/key8.xpm"
# define KEY9 "./IMG/key/key9.xpm"
# define KEY10 "./IMG/key/key10.xpm"
# define KEY11 "./IMG/key/key11.xpm"
# define PLAYER "./IMG/player.xpm"
# define ENEMY "./IMG/enemy.xpm"
# define EXIT_0 "./IMG/close_door.xpm"
# define EXIT_1 "./IMG/open_door.xpm"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}				t_img;

typedef struct s_player
{
	int		x;
	int		y;
	int		collect;
	int		steps;
	int		exit_done;
	t_img	*player;
}				t_player;

typedef struct s_map
{
	int		empty_space;
	int		wall;
	int		collect_max;
	int		map_exit;
	int		player;
	int		enemy;
	int		width;
	int		height;
	char	**map;
}				t_map;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	t_img		*enemy;
	t_mlx		*mlx;
	t_img		*wall;
	t_img		*background;
	t_img		*exit_0;
	t_img		*exit_1;
	t_img		*key;
}				t_game;

void	ft_exit(int malloc, char *str, t_game *game);

t_game	*ft_init(void);
void	ft_init_player(t_game *game);
void	ft_init_img(t_game *game);
void	ft_init_file(t_game *game, t_img *img, char *path);

void	ft_map_info(t_game *game, char *map_file);

void	ft_map_check_params(t_game *game, char *map_file);

void	ft_create_map(t_game *game, char *map_file);

int		ft_key_control(int keycode, t_game *game);

void	ft_check_collectable(t_game *game);
void	ft_check_exit(int keycode, t_game *game);
void	ft_check_die(t_game *game);

int		ft_render_loop(t_game *game);

size_t	ft_strlen(const char *str);

#endif