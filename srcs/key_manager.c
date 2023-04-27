/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:59:30 by datran            #+#    #+#             */
/*   Updated: 2023/03/30 11:44:49 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mlx_close(t_game *game)
{
	free_exit(game, "Game closed (X)");
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		free_exit(game, "Game closed (ESC)");
	movements(key, game);
	print_map(game);
	print_steps(game);
	return (0);
}
