/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:03:40 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/09 15:20:36 by ingrid           ###   ########.fr       */
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

static void	validate_map(char **map, int rows, int cols)
{
	if ((cols * rows) < 15)
		error_exit("Error: invalid map.");
	if (cols == rows)
		error_exit("Error: invalid map (not rectangular).");
	if (!has_walls_around(map, rows, cols))
		error_exit("Error: the map is not surrounded by walls.");
}

void	parse_and_validate_map(int fd_map)
{
	int		cols;
	int		rows;
	char	**map;
	t_list	*head;

	head = NULL;
	map = read_map(fd_map, &rows, &cols, &head);
	validate_map(map, rows, cols);
	free_array(map);
	free_list(&head);
}
