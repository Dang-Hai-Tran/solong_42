/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:07:40 by datran            #+#    #+#             */
/*   Updated: 2023/04/24 14:54:14 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_init_position(t_game *game)
{
	int		row;
	int		col;

	row = -1;
	while (++row < game->map.size.y)
	{
		col = -1;
		while (++col < game->map.size.x)
		{
			if (game->map.mtx[row][col] == 'P')
			{
				game->player.pos.x = col;
				game->player.pos.y = row;
			}
		}
	}
}

int	count_collects(t_game *game)
{
	int		row;
	int		col;

	row = -1;
	game->player.count_collects = 0;
	while (++row < game->map.size.y)
	{
		col = -1;
		while (++col < game->map.size.x)
		{
			if (game->map.mtx[row][col] == 'C')
				game->player.count_collects++;
		}
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
	ft_putstr_fd("Step:", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
}
