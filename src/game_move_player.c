/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:57:08 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/13 20:28:52 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_outside(t_game *g, int x, int y)
{
	if (x < 0 || x >= g->map.cols || y < 0 || y >= g->map.rows)
		return (1);
	return (0);
}

static int	handle_exit_tile(t_game *g)
{
	if (g->collected == g->map.checker['C'])
	{
		g->moves++;
		game_exit(g);
	}
	return (1);
}

static void	update_player_pos(t_game *g, int new_x, int new_y)
{
	g->map.grid[g->player_y][g->player_x] = '0';
	g->map.grid[new_y][new_x] = 'P';
	g->player_x = new_x;
	g->player_y = new_y;
}

static void	count_move_and_render(t_game *g)
{
	g->moves++;
	render_map(g);
}

void	move_player(t_game *g, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	dest;

	new_x = g->player_x + dx;
	new_y = g->player_y + dy;
	if (is_outside(g, new_x, new_y))
		return ;
	dest = g->map.grid[new_y][new_x];
	if (dest == '1')
		return ;
	if (dest == 'C')
		g->collected++;
	if (dest == 'E' && handle_exit_tile(g))
		return ;
	update_player_pos(g, new_x, new_y);
	count_move_and_render(g);
}
