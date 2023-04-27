/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:19:05 by datran            #+#    #+#             */
/*   Updated: 2023/03/30 13:17:31 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error_free(t_game *game, char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	free_map(game);
	exit(EXIT_FAILURE);
}
