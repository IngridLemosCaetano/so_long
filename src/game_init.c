/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:58:43 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/12 21:51:54 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_images(t_game *g)
{
	int	w;
	int	h;

	g->img->wall = mlx_xpm_file_to_image(g->mlx, "../textures/wall.xpm",
		&w, &h);
	g->img->floor = mlx_xpm_file_to_image(g->mlx, "../textures/floor.xpm",
		&w, &h);
	g->img->player = mlx_xpm_file_to_image(g->mlx, "../textures/player.xpm",
		&w, &h);
	g->img->exit = mlx_xpm_file_to_image(g->mlx, "../textures/exit.xpm",
		&w, &h);
	g->img->collect = mlx_xpm_file_to_image(g->mlx, "../textures/collect.xpm",
		&w, &h);
	if (!g->img->wall)
		error_exit("Error: no such file xpm (wall)");
	else if (!g->img->floor)
		error_exit("Error: no such file xpm (floor)");
	else if (!g->img->player)
		error_exit("Error: no such file xpm (player)");
	else if (!g->img->exit)
		error_exit("Error: no such file xpm (exit)");
	else if (!g->img->collect)
		error_exit("Error: no such file xpm (collect)");
}

void	game_init(t_game *game, int fd_map)
{
	read_map(fd_map, game->map);
	validate_map(&game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->cols * TILE),
	(game->rows * TILE), "so_long");
	load_images(game);
	find_player(&game->map, &game->player_x, &game->player_y);
	game->collected = 0;
}
