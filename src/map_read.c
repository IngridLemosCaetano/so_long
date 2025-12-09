/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:30:49 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/08 21:12:00 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	has_minimum_items(char *line, int *checker)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_c_valid(line[i]))
			error_exit("Error: map contains an invalid character.");
		checker[(unsigned char)line[i]]++;
		i++;
	}
}

static void	check_itens(int *checker)
{
	if (checker['P'] != 1)
		error_exit("Error: map must contain exactly one player (P).");
	if (checker['E'] != 1)
		error_exit("Error: map must contain exactly one exit (E).");
	if (checker['C'] < 1)
		error_exit("Error: map must contain at least one collectible (C).");
}

static int	count_rows(int fd_map)
{
	int		rows;
	char	*line;

	rows = 0;
	while ((line = get_next_line(fd_map)) != NULL)
	{
		rows++;
		free(line);
	}
	return (rows);
}

char	**read_map(int fd_map, int *rows, int *cols)
{
	char	**matrix;
	char	*line;
	int		checker[256];
	int		i;
	int		x;
	int		aux;

	*cols = 0;
	*rows = count_rows(fd_map);
	if (*rows == 0)
		error_exit("Error: empty map.");
	matrix = malloc(sizeof(char *) * (*rows));
	if (!matrix)
		error_exit("Error: malloc failed.");
	init_checker(checker, 256);
	i = 0;
	while ((line = get_next_line(fd_map)) != NULL)
	{
		has_minimum_items(line, checker);
		x = 0;
		while (line[x] && line[x] != '\n' && !is_space(line[x]))
			x++;
		aux = x;
		if (i > 0 && *cols != aux)
			error_exit("Error: invalid map (not rectangular).");
		*cols = aux;
		matrix[i] = ft_substr(line, 0, aux);
		if (!matrix)
			error_exit("Error: malloc failed.");
		free(line);
		i++;
	}
	check_itens(checker);
	return (matrix);
}

// static char	**is_matrix(int fd_map, int *cols, int *rows)
// {
// 	int		aux;
// 	int		x;
// 	char	*line;
// 	int		checker[256];
// 	char	**matrix = {0};
// 	int		i;

// 	*cols = 0;
// 	*rows = 0;
// 	i = 0;
// 	init_checker(checker, 256);
// 	while ((line = get_next_line(fd_map)) != NULL)
// 	{
// 		has_minimum_items(line, checker);
// 		matrix[i] = line;
// 		x = 0;
// 		while (line[x] && line[x] != '\n' && !is_space(line[x]))
// 		{
// 			if (!is_c_valid(line[x]))
// 				error_exit("Error: map contains an invalid character.");
// 			x++;
// 		}
// 		aux = x;
// 		if (*rows > 0 && *cols != aux)
// 			error_exit("Error: invalid map");
// 		*cols = aux;
// 		(*rows)++;
// 		i++;
// 		free(line);
// 	}

// 	return (matrix);
// }
