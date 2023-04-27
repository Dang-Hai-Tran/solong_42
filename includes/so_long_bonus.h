/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:44:57 by datran            #+#    #+#             */
/*   Updated: 2023/04/24 14:15:48 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_DESTROY	17

# define A_KEY	97
# define S_KEY	115
# define D_KEY	100
# define W_KEY	119
# define ESC	65307

# define SPRITE_Y	64
# define SPRITE_X	64

typedef struct s_vector
{
	int			x;
	int			y;
}	t_vector;

typedef struct s_img
{
	void		*img_ptr;
	char		*spt_path;
	t_vector	size;
}	t_img;

typedef struct s_map
{
	char		**mtx;
	t_vector	size;
}	t_map;

typedef struct s_player
{
	int			count_collects;
	int			count_steps;
	t_img		img;
	t_vector	pos;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_img		img;
	t_map		map;
	int			has_enemies;
}	t_game;

// error.c
void	error(char *msg);
void	error_free(t_game *game, char *msg);

// check_map.c
void	check_map(t_game *game);

// dfs_map.c
int		has_valid_path(int st_row, int st_col, t_map *map, int **visited);

// map.c
void	get_map_size(t_game *game, char **argv);
void	get_map_mtx(t_game *game, char **argv);
void	print_map(t_game *game);

// game.c
void	get_init_position(t_game *game);
int		count_collects(t_game *game);
void	check_collects(t_game *game);
void	print_steps(t_game *game);

// exit.c
void	free_map(t_game *game);
void	free_map_window(t_game *game);
void	free_exit(t_game *game, char *msg);

// key_manager.c
int		mlx_close(t_game *game);
int		key_press(int key, t_game *game);

// step_in_enemy.c
int		step_in_enemy(int key, t_game *game, int pos_x, int pos_y);

// movement.c
void	movements(int key, t_game *game);

#endif
