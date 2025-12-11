/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:03:40 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/10 10:58:40 by ingrid           ###   ########.fr       */
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

void	validate_map(char **map, int rows, int cols)
{
	if ((cols * rows) < 15)
		error_exit("Error: invalid map.");
	if (cols == rows)
		error_exit("Error: invalid map (not rectangular).");
	if (!has_walls_around(map, rows, cols))
		error_exit("Error: the map is not surrounded by walls.");
}
// void	validate_map(char **map, int rows, int cols)
// {
// 	t_position	player;

// 	if ((cols * rows) < 15)
// 		error_exit("Error: invalid map.");
// 	if (cols == rows)
// 		error_exit("Error: invalid map (not rectangular).");
// 	if (!has_walls_around(map, rows, cols))
// 		error_exit("Error: the map is not surrounded by walls.");
// 	player.visited = alloc_visited(rows, cols);
// 	if (!player.visited)
// 		error_exit("Error: malloc failed.");
// 	player.p_rows = -1;
// 	player.p_col = -1;
// 	player.i = 0;
// 	while (player.i < rows)
// 	{
// 		player.j = 0;
// 		while (player.j < cols)
// 		{
// 			if (map[player.i][player.j] == 'P')
// 			{
// 				player.p_rows = player.i;
// 				player.p_col = player.j;
// 			}
// 			player.j++;
// 		}
// 		player.i++;
// 	}
// 	dfs(map, &player, rows, cols, player.p_row, player.p_col);
// 	player.i = 0;
// 	while (player.i < rows)
// 	{
// 		player.j = 0;
// 		while (player.j < cols)
// 		{
// 			if ((map[player.i][player.j] == 'C' ||
// 				map[player.i][player.j] == 'E') &&
// 				!player.visited[player.i][player.j])
// 				error_exit("Error: invalid path");
// 			player.j++;
// 		}
// 		player.i++;
// 	}
// 	free_visited(player.visited, rows);
// }

void	parse_and_validate_map(int fd_map)
{
	int		cols;
	int		rows;
	char	**map;
	t_list	*head;

	head = NULL;
	map = read_map(fd_map, &rows, &cols, &head);
	// ft_printf("cols: %d, rows: %d\n", cols, rows);
	// ft_printf("%s", (char *)head->content);
	// ft_printf("%s", (char *)head->next->content);
	// ft_printf("%s", (char *)head->next->next->content);
	// ft_printf("%s", (char *)head->next->next->next->content);
	validate_map(map, rows, cols);
	free_array(map);
	free_list(&head);
}
