/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:10:30 by datran            #+#    #+#             */
/*   Updated: 2023/04/24 14:18:03 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	init(t_game *game)
{
	game->map.mtx = malloc((game->map.size.y + 1) * sizeof(char *));
	if (!game->map.mtx)
		error("Access malloc error");
	game->map.mtx[game->map.size.y] = NULL;
	game->player.count_steps = 0;
	game->img.size.x = 1;
	game->img.size.y = 1;
	game->player.img.spt_path = "./imgs/sprite.xpm";
	game->has_enemies = 0;
}

static void	check_args(int argc, char **argv)
{
	struct stat	p_stat;

	stat(argv[1], &p_stat);
	if (argc < 2)
		error("Invalid argument: No argument");
	if (argc > 2)
		error("Invalid argument: Too much arguments");
	if (ft_strlen(ft_strstr(argv[1], ".ber")) != 4)
		error("Invalid argument: Extension is not .ber");
	if (S_ISDIR(p_stat.st_mode))
		error("Invalid argument: Argument is a folder");
}

static int	**init_visited(int rows, int cols)
{
	int		**visited;
	int		row;

	visited = malloc(sizeof(int *) * rows);
	row = -1;
	while (++row < rows)
		visited[row] = calloc(cols, sizeof(int));
	return (visited);
}

int	main(int argc, char **argv)
{
	t_game		game;
	int			**visited;

	check_args(argc, argv);
	get_map_size(&game, argv);
	init(&game);
	get_map_mtx(&game, argv);
	get_init_position(&game);
	count_collects(&game);
	visited = init_visited(game.map.size.y, game.map.size.x);
	if (has_valid_path(game.player.pos.y, game.player.pos.x, \
		&game.map, visited) == 0)
		error_free(&game, "Not found valid path in map");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.size.x * SPRITE_X, \
		game.map.size.y * SPRITE_Y, "so long");
	print_map(&game);
	print_steps(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &game);
	mlx_hook(game.win, X_EVENT_DESTROY, 1L << 2, mlx_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
