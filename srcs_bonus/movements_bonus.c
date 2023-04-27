/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:06:23 by datran            #+#    #+#             */
/*   Updated: 2023/03/30 13:34:45 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	move_left(t_game *game)
{
	game->map.mtx[game->player.pos.y][game->player.pos.x] = '0';
	game->player.pos.x--;
	game->map.mtx[game->player.pos.y][game->player.pos.x] = 'P';
	game->player.count_steps++;
	game->player.img.spt_path = "./imgs/sprite2.xpm";
}

static void	move_right(t_game *game)
{
	game->map.mtx[game->player.pos.y][game->player.pos.x] = '0';
	game->player.pos.x++;
	game->map.mtx[game->player.pos.y][game->player.pos.x] = 'P';
	game->player.count_steps++;
	game->player.img.spt_path = "./imgs/sprite1.xpm";
}

static void	move_down(t_game *game)
{
	game->map.mtx[game->player.pos.y][game->player.pos.x] = '0';
	game->player.pos.y++;
	game->map.mtx[game->player.pos.y][game->player.pos.x] = 'P';
	game->player.count_steps++;
}

static void	move_up(t_game *game)
{
	game->map.mtx[game->player.pos.y][game->player.pos.x] = '0';
	game->player.pos.y--;
	game->map.mtx[game->player.pos.y][game->player.pos.x] = 'P';
	game->player.count_steps++;
}

void	movements(int key, t_game *game)
{
	int		pos_x;
	int		pos_y;

	pos_x = game->player.pos.x;
	pos_y = game->player.pos.y;
	if (step_in_enemy(key, game, pos_x, pos_y) == 1)
		free_exit(game, "Move into enemy. You lost");
	if ((key == A_KEY) && game->map.mtx[pos_y][pos_x - 1] == 'E')
		check_collects(game);
	else if ((key == A_KEY) && game->map.mtx[pos_y][pos_x - 1] != '1')
		move_left(game);
	if ((key == S_KEY) && game->map.mtx[pos_y + 1][pos_x] == 'E')
		check_collects(game);
	else if ((key == S_KEY) && game->map.mtx[pos_y + 1][pos_x] != '1')
		move_down(game);
	if ((key == D_KEY) && game->map.mtx[pos_y][pos_x + 1] == 'E')
		check_collects(game);
	else if ((key == D_KEY) && game->map.mtx[pos_y][pos_x + 1] != '1')
		move_right(game);
	if ((key == W_KEY) && game->map.mtx[pos_y - 1][pos_x] == 'E')
		check_collects(game);
	else if ((key == W_KEY) && game->map.mtx[pos_y - 1][pos_x] != '1')
		move_up(game);
}
