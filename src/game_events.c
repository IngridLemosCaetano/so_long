/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:04:49 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/13 15:23:41 by ingrid           ###   ########.fr       */
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

static void	move_player(t_game *g, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	dest;

	new_x = g->player_x + dx;
	new_y = g->player_y + dy;
	if (new_x < 0 || new_x >= g->map.cols || new_y < 0 || new_y >= g->map.rows)
		return ;
	dest = g->map.grid[new_y][new_x];
	if (dest == '1')
		return ;
	if (dest == 'C')
		g->collected++;
	if (dest == 'E')
	{
		if (g->collected == g->map.checker['C'])
			game_exit(g);
		return ;
	}
	g->map.grid[g->player_y][g->player_x] = '0';
	g->map.grid[new_y][new_x] = 'P';
	g->player_x = new_x;
	g->player_y = new_y;
	render_map(g);
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

int	handle_key(int keycode, t_game *g)
{
	(void)g;
	ft_printf("count move = %d\n", keycode);
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

int	handle_close(t_game *g)
{
	return (game_exit(g));
}
