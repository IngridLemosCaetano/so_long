/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:31:30 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/12 11:23:34 by ingrid           ###   ########.fr       */
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
	init_window();
	return (0);
}

void	init_window(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
	void	*background;
	char	*player_path = "../assets/sprites/character.xpm";
	char	*player_col = "../assets/sprites/fan.xpm";
	char	*player_exit = "../assets/sprites/castle.xpm";
	char	*player_wall = "../assets/sprites/texture_wall.xpm";
	char	*player_back = "../assets/sprites/background.xpm";
	int		img_width;
	int		img_height;

	img_height = 68;
	img_width = 68;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1156, 680, "so_long");
	player = mlx_xpm_file_to_image(mlx, player_path, &img_width, &img_height);
	collectible = mlx_xpm_file_to_image(mlx, player_col, &img_width, &img_height);
	exit = mlx_xpm_file_to_image(mlx, player_exit, &img_width, &img_height);
	wall = mlx_xpm_file_to_image(mlx, player_wall, &img_width, &img_height);
	background = mlx_xpm_file_to_image(mlx, player_back, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, player, 68, 68);
	mlx_put_image_to_window(mlx, mlx_win, collectible, 408, 272);
	mlx_put_image_to_window(mlx, mlx_win, collectible, 748, 408);
	mlx_put_image_to_window(mlx, mlx_win, exit, 1020, 544);
	//top
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 68, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 136, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 204, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 204, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 272, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 340, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 408, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 476, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 544, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 612, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 680, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 748, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 816, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 884, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 952, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1020, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1088, 0);
	//down
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 68, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 136, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 204, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 204, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 272, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 340, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 408, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 476, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 544, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 612, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 680, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 748, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 816, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 884, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 952, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1020, 612);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1088, 612);
	//left
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 68);
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 136);
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 204);
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 272);
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 340);
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 408);
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 476);
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 544);
	//right
	mlx_put_image_to_window(mlx, mlx_win, wall, 1088, 68);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1088, 136);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1088, 204);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1088, 272);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1088, 340);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1088, 408);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1088, 476);
	mlx_put_image_to_window(mlx, mlx_win, wall, 1088, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 68, 204);

	mlx_loop(mlx);
}
