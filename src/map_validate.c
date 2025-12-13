/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:03:40 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/12 20:43:38 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	has_walls_around(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

// static void	validate_path(t_map *map)
// {

// }

void	validate_map(t_map *map)
{
	if ((map->cols * map->rows) < 15)
		error_exit("Error: invalid map.");
	if (map->cols == map->rows)
		error_exit("Error: invalid map (not rectangular).");
	if (!has_walls_around(map->grid, map->rows, map->cols))
		error_exit("Error: the map is not surrounded by walls.");
}
