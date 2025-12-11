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
	mlx_win = mlx_new_window(mlx, 1200, 700, "So Long");
	player = mlx_xpm_file_to_image(mlx, player_path, &img_width, &img_height);
	collectible = mlx_xpm_file_to_image(mlx, player_col, &img_width, &img_height);
	exit = mlx_xpm_file_to_image(mlx, player_exit, &img_width, &img_height);
	wall = mlx_xpm_file_to_image(mlx, player_wall, &img_width, &img_height);
	background = mlx_xpm_file_to_image(mlx, player_back, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, player, 68, 68);
	mlx_put_image_to_window(mlx, mlx_win, wall, 0, 0);
	mlx_loop(mlx);
}
