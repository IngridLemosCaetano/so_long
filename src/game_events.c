/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:04:49 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/13 01:38:43 by ingrid           ###   ########.fr       */
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

int	handle_key(int keycode, t_game *g)
{
	if (keycode == 65307)
		game_exit(g);
	// mover jogador (WASD ou setas): atualiza map.grid e player_x/y e mostrar no terminal a qtd movimentos
	// depois redesenha só o necessário ou chama render_map(g)
	return (0);
}

int	handle_close(t_game *g)
{
	return (game_exit(g));
}
