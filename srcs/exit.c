/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:33:48 by datran            #+#    #+#             */
/*   Updated: 2023/04/24 14:09:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int		row;

	row = -1;
	while (++row < game->map.size.y)
		free(game->map.mtx[row]);
	free(game->map.mtx);
}

void	free_map_window(t_game *game)
{
	int		row;

	row = -1;
	while (++row < game->map.size.y)
		free(game->map.mtx[row]);
	free(game->map.mtx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_exit(t_game *game, char *msg)
{
	ft_putendl_fd(msg, 1);
	free_map_window(game);
	exit(EXIT_SUCCESS);
}
