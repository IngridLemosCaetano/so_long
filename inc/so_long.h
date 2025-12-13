/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:31:24 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/12 21:52:22 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <sys/time.h>
# include <math.h>

# define TILE 68

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
}	t_game;

//map_utils
int		is_c_valid(char c);
void	init_checker(int *checker, int size);
void	free_list(t_list **head);

//map_read
void	read_map(int fd_map, t_map *map);

//map_validate
void	validate_map(t_map *map);

//utils
char	*error_exit(char *message);
int		is_space(char c);
void	free_array(char **arr);

//map_dfs
int		**alloc_visited(int rows, int cols);
void	free_visited(int **matrix, int rows);

//game_init
void	game_init(t_game *game, int fd_map)

//game_render

#endif
