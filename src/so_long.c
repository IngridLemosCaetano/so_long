/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:31:30 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/11 14:47:33 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char *av[])
{
	int		fd_map;

	if (ac == 2)
	{
		fd_map = open(av[1], O_RDONLY);
		if (fd_map < 0)
			error_exit("Error: no such file or directory");
		parse_and_validate_map(fd_map);
		close(fd_map);
	}
	else
		error_exit("Error: no map file provided.");
	return (0);
}

void	init_window(int rows, int cols, int len)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, cols * len, rows * len, "so_long");
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);
}
