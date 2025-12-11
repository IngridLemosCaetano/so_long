/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:05:34 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/10 10:58:44 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	**alloc_visited(int rows, int cols)
{
	int	**matrix;
	int	i;

	matrix = (int **)malloc(sizeof(int *) * rows)
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = malloc(sizeof(int) * cols);
		if (!matrix[i])
			return (NULL);
		ft_bzero(matrix[i], sizeof(int) * cols);
		i++;
	}
	return (matrix);
}

static void	free_visited(int **matrix, int rows)
{
	int	i ;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

// static void	dfs(char **map, t_position p)
// {
// 	if (p->p_rows < 0 || p->p_rows >= p->rows || p->p_col < 0 ||
// 		p->p_col >= p->cols)
// 		return ;
// 	if (map[p->p_row][p->p_col] == 1)
// 		return ;
// 	if (p->visited[p->p_row][p->p_col])
// 		return ;
// 	p->visited[p->p_row][p->p_col] = 1;

// }
