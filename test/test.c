#include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	char	*relative_path = "../assets/sprites/character.xpm";

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1200, 700, "So Long");
// 	img.img = mlx_new_image(mlx, 68, 68);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 0, 0, 0x00FFFFFF);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 65, 65);
// 	mlx_loop(mlx);
// }


#include <mlx.h>

int	main(void)
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

	// img_height = 68;
	// img_width = 68;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1156, 680, "So Long");
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
	//4
	mlx_put_image_to_window(mlx, mlx_win, wall, 340, 68);
	mlx_put_image_to_window(mlx, mlx_win, wall, 408, 68);
	mlx_put_image_to_window(mlx, mlx_win, wall, 476, 68);
	mlx_put_image_to_window(mlx, mlx_win, wall, 340, 136);
	mlx_put_image_to_window(mlx, mlx_win, wall, 272, 136);
	mlx_put_image_to_window(mlx, mlx_win, wall, 272, 204);
	mlx_put_image_to_window(mlx, mlx_win, wall, 204, 204);
	mlx_put_image_to_window(mlx, mlx_win, wall, 204, 272);
	mlx_put_image_to_window(mlx, mlx_win, wall, 204, 340);
	mlx_put_image_to_window(mlx, mlx_win, wall, 272, 340);
	mlx_put_image_to_window(mlx, mlx_win, wall, 340, 340);
	mlx_put_image_to_window(mlx, mlx_win, wall, 408, 340);
	mlx_put_image_to_window(mlx, mlx_win, wall, 476, 340);
	mlx_put_image_to_window(mlx, mlx_win, wall, 544, 340);
	mlx_put_image_to_window(mlx, mlx_win, wall, 476, 272);
	mlx_put_image_to_window(mlx, mlx_win, wall, 476, 204);
	mlx_put_image_to_window(mlx, mlx_win, wall, 476, 408);
	mlx_put_image_to_window(mlx, mlx_win, wall, 476, 476);
	//2
	mlx_put_image_to_window(mlx, mlx_win, wall, 680, 68);
	mlx_put_image_to_window(mlx, mlx_win, wall, 748, 68);
	mlx_put_image_to_window(mlx, mlx_win, wall, 816, 68);
	mlx_put_image_to_window(mlx, mlx_win, wall, 884, 68);
	mlx_put_image_to_window(mlx, mlx_win, wall, 680, 136);
	mlx_put_image_to_window(mlx, mlx_win, wall, 884, 136);
	mlx_put_image_to_window(mlx, mlx_win, wall, 816, 204);
	mlx_put_image_to_window(mlx, mlx_win, wall, 884, 204);
	mlx_put_image_to_window(mlx, mlx_win, wall, 748, 272);
	mlx_put_image_to_window(mlx, mlx_win, wall, 816, 272);
	mlx_put_image_to_window(mlx, mlx_win, wall, 680, 340);
	mlx_put_image_to_window(mlx, mlx_win, wall, 748, 340);
	mlx_put_image_to_window(mlx, mlx_win, wall, 680, 408);
	mlx_put_image_to_window(mlx, mlx_win, wall, 680, 476);
	mlx_put_image_to_window(mlx, mlx_win, wall, 748, 476);
	mlx_put_image_to_window(mlx, mlx_win, wall, 816, 476);
	mlx_put_image_to_window(mlx, mlx_win, wall, 884, 476);
	mlx_put_image_to_window(mlx, mlx_win, wall, 884, 408);
	//background
	mlx_put_image_to_window(mlx, mlx_win, background, 68, 204);
	mlx_put_image_to_window(mlx, mlx_win, background, 136, 68);
	mlx_put_image_to_window(mlx, mlx_win, background, 204, 68);
	mlx_put_image_to_window(mlx, mlx_win, background, 272, 68);
	mlx_put_image_to_window(mlx, mlx_win, background, 68, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 136, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 204, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 408, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 476, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 136, 204);
	mlx_put_image_to_window(mlx, mlx_win, background, 340, 204);
	mlx_put_image_to_window(mlx, mlx_win, background, 408, 204);
	mlx_put_image_to_window(mlx, mlx_win, background, 340, 272);
	mlx_put_image_to_window(mlx, mlx_win, background, 272, 272);
	mlx_put_image_to_window(mlx, mlx_win, background, 68, 272);
	mlx_put_image_to_window(mlx, mlx_win, background, 136, 272);
	mlx_put_image_to_window(mlx, mlx_win, background, 68, 340);
	mlx_put_image_to_window(mlx, mlx_win, background, 136, 340);
	mlx_put_image_to_window(mlx, mlx_win, background, 68, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 136, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 204, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 272, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 340, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 408, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 68, 476);
	mlx_put_image_to_window(mlx, mlx_win, background, 136, 476);
	mlx_put_image_to_window(mlx, mlx_win, background, 204, 476);
	mlx_put_image_to_window(mlx, mlx_win, background, 272, 476);
	mlx_put_image_to_window(mlx, mlx_win, background, 340, 476);
	mlx_put_image_to_window(mlx, mlx_win, background, 408, 476);
	mlx_put_image_to_window(mlx, mlx_win, background, 68, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 136, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 204, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 272, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 340, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 408, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 476, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 544, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 544, 476);
	mlx_put_image_to_window(mlx, mlx_win, background, 544, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 544, 272);
	mlx_put_image_to_window(mlx, mlx_win, background, 544, 204);
	mlx_put_image_to_window(mlx, mlx_win, background, 544, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 544, 68);
	mlx_put_image_to_window(mlx, mlx_win, background, 612, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 612, 476);
	mlx_put_image_to_window(mlx, mlx_win, background, 612, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 612, 340);
	mlx_put_image_to_window(mlx, mlx_win, background, 612, 272);
	mlx_put_image_to_window(mlx, mlx_win, background, 612, 204);
	mlx_put_image_to_window(mlx, mlx_win, background, 612, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 612, 68);
	mlx_put_image_to_window(mlx, mlx_win, background, 816, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 816, 340);
	mlx_put_image_to_window(mlx, mlx_win, background, 884, 340);
	mlx_put_image_to_window(mlx, mlx_win, background, 884, 272);
	mlx_put_image_to_window(mlx, mlx_win, background, 680, 272);
	mlx_put_image_to_window(mlx, mlx_win, background, 680, 204);
	mlx_put_image_to_window(mlx, mlx_win, background, 748, 204);
	mlx_put_image_to_window(mlx, mlx_win, background, 748, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 816, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 952, 68);
	mlx_put_image_to_window(mlx, mlx_win, background, 952, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 952, 204);
	mlx_put_image_to_window(mlx, mlx_win, background, 952, 272);
	mlx_put_image_to_window(mlx, mlx_win, background, 952, 340);
	mlx_put_image_to_window(mlx, mlx_win, background, 952, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 952, 476);
	mlx_put_image_to_window(mlx, mlx_win, background, 952, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 1020, 68);
	mlx_put_image_to_window(mlx, mlx_win, background, 1020, 136);
	mlx_put_image_to_window(mlx, mlx_win, background, 1020, 204);
	mlx_put_image_to_window(mlx, mlx_win, background, 1020, 272);
	mlx_put_image_to_window(mlx, mlx_win, background, 1020, 340);
	mlx_put_image_to_window(mlx, mlx_win, background, 1020, 408);
	mlx_put_image_to_window(mlx, mlx_win, background, 1020, 476);
	mlx_put_image_to_window(mlx, mlx_win, background, 884, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 816, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 748, 544);
	mlx_put_image_to_window(mlx, mlx_win, background, 680, 544);

	mlx_loop(mlx);
}
