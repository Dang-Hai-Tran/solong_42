/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:07:40 by datran            #+#    #+#             */
/*   Updated: 2023/03/30 13:40:54 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_init_position(t_game *game)
{
	int		row;
	int		col;

	row = 0;
	while (row < game->map.size.y)
	{
		col = 0;
		while (col < game->map.size.x)
		{
			if (game->map.mtx[row][col] == 'P')
			{
				game->player.pos.x = col;
				game->player.pos.y = row;
			}
			col++;
		}
		row++;
	}
}

int	count_collects(t_game *game)
{
	int		row;
	int		col;

	row = 0;
	game->player.count_collects = 0;
	while (row < game->map.size.y)
	{
		col = 0;
		while (col < game->map.size.x)
		{
			if (game->map.mtx[row][col] == 'C')
				game->player.count_collects++;
			col++;
		}
		row++;
	}
	return (game->player.count_collects);
}

void	check_collects(t_game *game)
{
	if (count_collects(game) == 0)
		free_exit(game, "You won");
	else
		ft_putendl_fd("Please collect all diamonds", 2);
}

void	print_steps(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.count_steps);
	mlx_string_put(game->mlx, game->win, SPRITE_X * game->player.pos.x + 10, \
	SPRITE_Y * game->player.pos.y + 10, 0xFF0000, str);
	free(str);
}
