/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:06:22 by datran            #+#    #+#             */
/*   Updated: 2023/03/30 16:47:57 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	check_walls(t_game *game)
{
	int		row;
	int		col;

	row = -1;
	while (++row < game->map.size.y)
	{
		col = -1;
		if (row == 0 || row == (game->map.size.y - 1))
		{
			while (++col < game->map.size.x)
			{
				if (game->map.mtx[row][col] != '1')
					error_free(game, "Invalid map: Top or down walls");
			}
		}
		else if (game->map.mtx[row][0] != '1' ||
			game->map.mtx[row][game->map.size.x - 1] != '1')
			error_free(game, "Invalid map: Right or left walls");
	}
}

static void	check_sprites(t_game *game)
{
	int		has[3];
	int		row;
	int		col;

	row = -1;
	has[0] = 0;
	has[1] = 0;
	has[2] = 0;
	while (++row < game->map.size.y)
	{
		col = -1;
		while (++col < game->map.size.x)
		{
			if (game->map.mtx[row][col] == 'P')
				has[0]++;
			if (game->map.mtx[row][col] == 'E')
				has[1]++;
			if (game->map.mtx[row][col] == 'C')
				has[2]++;
		}
	}
	if (has[0] != 1 || has[1] != 1 || has[2] == 0)
		error_free(game, "Invalid map: Missing in PEC");
}

static void	check_rectangle(t_game *game)
{
	int		row;

	row = -1;
	while (++row < game->map.size.y)
	{
		if (game->map.size.x != (int)ft_strlen(game->map.mtx[row]))
			error_free(game, "Invalid map: Map is not a rectangle");
	}
}

static void	check_chars(t_game *game)
{
	int		row;
	int		col;
	char	c;

	row = -1;
	while (++row < game->map.size.y)
	{
		col = -1;
		while (++col < game->map.size.x)
		{
			c = game->map.mtx[row][col];
			if (c != '0' && c != '1' && c != 'P' && c != 'E' \
			&& c != 'C' && c != 'Y')
				error_free(game, "Invalid map: Unknown char (hors 01PECY)");
			if (c == 'Y')
				game->has_enemies++;
		}
	}
}

void	check_map(t_game *game)
{
	check_walls(game);
	check_sprites(game);
	check_rectangle(game);
	check_chars(game);
}
