/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:20:12 by datran            #+#    #+#             */
/*   Updated: 2023/04/24 14:04:02 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_map(t_map *map)
{
	char	**cp_map;
	int		row;

	cp_map = malloc(sizeof(char *) * map->size.y);
	row = -1;
	while (++row < map->size.y)
		cp_map[row] = ft_strdup(map->mtx[row]);
	return (cp_map);
}

void	free_cpmap_visited(t_map *map, int **visited)
{
	int	row;

	row = -1;
	while (++row < map->size.y)
	{
		free(map->mtx[row]);
		free(visited[row]);
	}
	free(map->mtx);
	free(visited);
}

void	dfs_map(int st_row, int st_col, t_map *map, int **visited)
{
	if (st_row < 0 || st_row >= map->size.y || st_col < 0 || st_col \
	>= map->size.x || visited[st_row][st_col] == 1 \
	|| map->mtx[st_row][st_col] == '1' || map->mtx[st_row][st_col] == 'Y')
		return ;
	if (map->mtx[st_row][st_col] == 'E')
	{
		map->mtx[st_row][st_col] = 'P';
		visited[st_row][st_col] = 1;
		return ;
	}
	map->mtx[st_row][st_col] = 'P';
	visited[st_row][st_col] = 1;
	dfs_map(st_row + 1, st_col, map, visited);
	dfs_map(st_row - 1, st_col, map, visited);
	dfs_map(st_row, st_col + 1, map, visited);
	dfs_map(st_row, st_col - 1, map, visited);
}

int	has_valid_path(int st_row, int st_col, t_map *map, int **visited)
{
	t_map	cp_map;
	int		row;

	cp_map.size.x = map->size.x;
	cp_map.size.y = map->size.y;
	cp_map.mtx = copy_map(map);
	dfs_map(st_row, st_col, &cp_map, visited);
	row = -1;
	while (++row < cp_map.size.y)
	{
		if (ft_strchr(cp_map.mtx[row], 'C') || ft_strchr(cp_map.mtx[row], 'E'))
		{
			free_cpmap_visited(&cp_map, visited);
			return (0);
		}
	}
	free_cpmap_visited(&cp_map, visited);
	return (1);
}
