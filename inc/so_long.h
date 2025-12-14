/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:31:24 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/14 14:41:08 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <sys/time.h>
# include <math.h>

# define TILE 68
# define W 119
# define S 115
# define A 97
# define D 100

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**grid;
	int		checker[256];
	t_list	*head;
}	t_map;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collect;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		player_x;
	int		player_y;
	int		collected;
	int		moves;
}	t_game;

typedef struct s_map_ctx
{
	char	**grid;
	int		rows;
	int		cols;
}	t_map_ctx;

typedef struct s_path_info
{
	int	reachable_c;
	int	reachable_e;
}	t_path_info;

int		is_c_valid(char c);
void	init_checker(int *checker, int size);
void	free_list(t_list **head);

void	read_map(int fd_map, t_map *map);

void	validate_map(t_map *map);
void	validate_path_map(t_game *g);

char	*error_exit(char *message);
int		is_space(char c);
void	free_array(char **arr);
void	valid_path(char *path);

int		**alloc_visited(int rows, int cols);
void	free_visited(int **matrix, int rows);

void	game_init(t_game *g, int fd_map);
void	render_map(t_game *g);
int		handle_key(int keycode, t_game *g);
int		handle_close(t_game *g);
int		game_exit(t_game *g);
void	move_player(t_game *g, int dx, int dy);

#endif
