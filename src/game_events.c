/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:04:49 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/13 16:22:07 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	destroy_images(t_game *g)
{
	if (g->img.wall)
		mlx_destroy_image(g->mlx, g->img.wall);
	if (g->img.floor)
		mlx_destroy_image(g->mlx, g->img.floor);
	if (g->img.player)
		mlx_destroy_image(g->mlx, g->img.player);
	if (g->img.exit)
		mlx_destroy_image(g->mlx, g->img.exit);
	if (g->img.collect)
		mlx_destroy_image(g->mlx, g->img.collect);
}

int	handle_key(int keycode, t_game *g)
{
	if (keycode == 65307)
		game_exit(g);
	else if (keycode == W)
		move_player(g, 0, -1);
	else if (keycode == S)
		move_player(g, 0, 1);
	else if (keycode == A)
		move_player(g, -1, 0);
	else if (keycode == D)
		move_player(g, 1, 0);
	return (0);
}

static void	free_map(t_map *m)
{
	int	i;

	if (!m->grid)
		return ;
	i = 0;
	while (m->grid[i])
	{
		free(m->grid[i]);
		i++;
	}
	free(m->grid);
	m->grid = NULL;
}

int	game_exit(t_game *g)
{
	destroy_images(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	free_map(&g->map);
	exit(0);
}

int	handle_close(t_game *g)
{
	return (game_exit(g));
}
