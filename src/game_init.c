/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:58:43 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/13 21:48:55 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_images(t_game *g)
{
	int	w;
	int	h;

	g->img.wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm",
			&w, &h);
	g->img.floor = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm",
			&w, &h);
	g->img.player = mlx_xpm_file_to_image(g->mlx, "textures/player.xpm",
			&w, &h);
	g->img.exit = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm",
			&w, &h);
	g->img.collect = mlx_xpm_file_to_image(g->mlx, "textures/collect.xpm",
			&w, &h);
	if (!g->img.wall)
		error_exit("Error: no such file xpm (wall)");
	else if (!g->img.floor)
		error_exit("Error: no such file xpm (floor)");
	else if (!g->img.player)
		error_exit("Error: no such file xpm (player)");
	else if (!g->img.exit)
		error_exit("Error: no such file xpm (exit)");
	else if (!g->img.collect)
		error_exit("Error: no such file xpm (collect)");
}

static void	find_player(t_map *map, int *player_x, int *player_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols && map->grid[y][x])
		{
			if (map->grid[y][x] == 'P')
			{
				*player_y = y;
				*player_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
	error_exit("Error: player not found in map.");
}

void	game_init(t_game *g, int fd_map)
{
	read_map(fd_map, &g->map);
	validate_map(&g->map);
	find_player(&g->map, &g->player_x, &g->player_y);
	validate_path_map(g);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->map.cols * TILE,
			g->map.rows * TILE, "so_long");
	load_images(g);
	g->collected = 0;
	g->moves = 0;
	render_map(g);
}
