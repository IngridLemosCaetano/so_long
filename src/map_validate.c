/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:03:40 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/08 20:53:07 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	has_walls_around(char **map, int rows, int cols)
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

void	validate_map(char **map, int rows, int cols)
{
	if ((cols * rows) < 15 || cols == rows)
		error_exit("Error: invalid map. Only rectangular maps are valid.");
	if (!has_walls_around(map, rows, cols))
		error_exit("Error: the map is not surrounded by walls.");
}

void	is_map_valid(int fd_map)
{
	int		cols;
	int		rows;
	char	**map;

	map = read_map(fd_map, &rows, &cols);
	validate_map(map, rows, cols);
	// depois você pode guardar matrix em t_game, ou dar free se não for usar
}
