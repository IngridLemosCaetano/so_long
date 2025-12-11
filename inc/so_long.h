/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:31:24 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/10 12:21:16 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/inc/libft.h"
# include <sys/time.h>
# include <math.h>
# include <mlx.h>

typedef struct s_map_info
{
	int		*rows;
	int		*cols;
	int		*checker;
	t_list	**head;
}	t_map_info;

typedef struct s_position
{
	int	p_row;
	int	p_col;
	int	i;
	int	j;
	int	**visited;
}	t_position;

int		is_c_valid(char c);
void	init_checker(int *checker, int size);
void	free_list(t_list **head);

char	**read_map(int fd_map, int *rows, int *cols, t_list **head);

void	validate_map(char **map, int rows, int cols);
void	parse_and_validate_map(int fd_map);

char	*error_exit(char *message);
int		is_space(char c);
void	free_array(char **arr);

#endif
