/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:03:40 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/14 17:54:02 by ilemos-c         ###   ########.fr       */
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

void	validate_map(t_map *map)
{
	if ((map->cols * map->rows) < 15)
		error_exit("Error: invalid map.");
	if (!has_walls_around(map->grid, map->rows, map->cols))
		error_exit("Error: the map is not surrounded by walls.");
}

static char	**duplicate_grid(char **src, int rows)
{
	char	**dest;
	int		i;

	dest = malloc(sizeof(char *) * (rows + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
			error_exit("Error: malloc failed.");
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

static void	dfs(t_map_ctx *map_ctx, int x, int y, t_path_info *info)
{
	char	tile;

	if (x < 0 || x >= map_ctx->cols || y < 0 || y >= map_ctx->rows)
		return ;
	tile = map_ctx->grid[y][x];
	if (tile == '1' || tile == 'V')
		return ;
	if (tile == 'C')
		info->reachable_c++;
	if (tile == 'E')
		info->reachable_e = 1;
	map_ctx->grid[y][x] = 'V';
	dfs(map_ctx, x + 1, y, info);
	dfs(map_ctx, x - 1, y, info);
	dfs(map_ctx, x, y + 1, info);
	dfs(map_ctx, x, y - 1, info);
}

void	validate_path_map(t_game *g)
{
	t_map_ctx	ctx;
	t_path_info	info;
	char		**copy;

	copy = duplicate_grid(g->map.grid, g->map.rows);
	if (!copy)
		error_exit("Error: malloc failed.");
	ctx.grid = copy;
	ctx.rows = g->map.rows;
	ctx.cols = g->map.cols;
	info.reachable_c = 0;
	info.reachable_e = 0;
	dfs(&ctx, g->player_x, g->player_y, &info);
	free_array(copy);
	if (info.reachable_c != g->map.checker['C'])
		error_exit("Error: not all collectibles are reachable.");
	if (info.reachable_e == 0)
		error_exit("Error: exit is not reachable.");
}
