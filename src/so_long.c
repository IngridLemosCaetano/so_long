/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:31:30 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/13 19:01:20 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char *av[])
{
	int		fd_map;
	t_game	g;

	if (ac == 2)
	{
		fd_map = open(av[1], O_RDONLY);
		if (fd_map < 0)
			error_exit("Error: no such file or directory");
		valid_path(av[1]);
		game_init(&g, fd_map);
		mlx_key_hook(g.win, handle_key, &g);
		mlx_hook(g.win, 17, 0, handle_close, &g);
		mlx_loop(g.mlx);
		free_array(g.map.grid);
		close(fd_map);
	}
	else
		error_exit("Error: no map file provided.");
	return (0);
}
