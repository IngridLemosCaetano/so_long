/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:51:38 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/13 16:48:47 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	put_tile(t_game *g, char c, int x, int y)
{
	void	*img;

	img = g->img.floor;
	if (c == '1')
		img = g->img.wall;
	else if (c == 'P')
		img = g->img.player;
	else if (c == 'E')
		img = g->img.exit;
	else if (c == 'C')
		img = g->img.collect;
	if (!img)
		return ;
	mlx_put_image_to_window(g->mlx, g->win, img, x * TILE, y * TILE);
}

static void	draw_moves(t_game *g)
{
	char	*str;

	str = ft_itoa(g->moves);
	if (!str)
		return ;
	mlx_string_put(g->mlx, g->win, 9, 11, 0x000000FF, str);
	mlx_string_put(g->mlx, g->win, 8, 10, 0xFFFFFFFF, str);
	free(str);
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.rows)
	{
		x = 0;
		while (x < g->map.cols && g->map.grid[y][x])
		{
			put_tile(g, g->map.grid[y][x], x, y);
			x++;
		}
		y++;
	}
	draw_moves(g);
}
