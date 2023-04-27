/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_in_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:58:31 by datran            #+#    #+#             */
/*   Updated: 2023/03/30 13:28:46 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	step_in_enemy(int key, t_game *game, int pos_x, int pos_y)
{
	if (game->has_enemies > 0)
	{
		if (key == A_KEY && game->map.mtx[pos_y][pos_x - 1] == 'Y')
			return (1);
		if (key == D_KEY && game->map.mtx[pos_y][pos_x + 1] == 'Y')
			return (1);
		if (key == W_KEY && game->map.mtx[pos_y - 1][pos_x] == 'Y')
			return (1);
		if (key == S_KEY && game->map.mtx[pos_y + 1][pos_x] == 'Y')
			return (1);
	}
	return (0);
}
