/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:37:51 by datran            #+#    #+#             */
/*   Updated: 2023/03/30 16:51:59 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_size(t_game *game, char **argv)
{
	int		fd;
	char	*line;

	game->map.size.x = 0;
	game->map.size.y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Cant open map");
	while (ft_gnl(fd, &line))
	{
		game->map.size.x = ft_strlen(line);
		game->map.size.y++;
		free(line);
	}
	close(fd);
	if (game->map.size.y == 0)
		error("Invalid map: Map is empty");
}

void	get_map_mtx(t_game *game, char **argv)
{
	int		row;
	int		fd;

	row = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Cant open map");
	while (ft_gnl(fd, &game->map.mtx[row]))
		row++;
	close(fd);
	check_map(game);
}

static void	load_map(t_game *game, int row, int col)
{
	if (game->map.mtx[row][col] == '1')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		"./imgs/tree.xpm", &game->img.size.x, &game->img.size.y);
	else if (game->map.mtx[row][col] == '0')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		"./imgs/floor.xpm", &game->img.size.x, &game->img.size.y);
	else if (game->map.mtx[row][col] == 'E')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		"./imgs/exit.xpm", &game->img.size.x, &game->img.size.y);
	else if (game->map.mtx[row][col] == 'C')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		"./imgs/collect.xpm", &game->img.size.x, &game->img.size.y);
	else if (game->map.mtx[row][col] == 'P')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		game->player.img.spt_path, &game->img.size.x, &game->img.size.y);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, \
	SPRITE_X * col, SPRITE_Y * row);
	mlx_destroy_image(game->mlx, game->img.img_ptr);
}

void	print_map(t_game *game)
{
	int		row;
	int		col;

	row = 0;
	while (row < game->map.size.y)
	{
		col = 0;
		while (col < game->map.size.x)
		{
			load_map(game, row, col);
			col++;
		}
		row++;
	}
}
