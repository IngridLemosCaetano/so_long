/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:30:49 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/09 16:59:30 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	count_map_chars(char *line, int *checker)
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

static void	check_itens(int *checker, int *rows)
{
	if (*rows == 0)
		error_exit("Error: empty map.");
	if (checker['P'] != 1)
		error_exit("Error: map must contain exactly one player (P).");
	if (checker['E'] != 1)
		error_exit("Error: map must contain exactly one exit (E).");
	if (checker['C'] < 1)
		error_exit("Error: map must contain at least one collectible (C).");
}

static char	**list_matrix(t_list *head, int rows)
{
	char	**matrix;
	int		i;

	matrix = malloc(sizeof(char *) * (rows + 1));
	if (!matrix)
		error_exit("Error: malloc failed.");
	i = 0;
	while (head)
	{
		matrix[i] = head->content;
		head = head->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

static void	process_map_line(char *line, t_map_info *info)
{
	t_list	*node;
	int		len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (*info->rows == 0)
		*info->cols = len;
	else if (*info->cols != len)
		error_exit("Error: invalid map (not rectangular).");
	count_map_chars(line, info->checker);
	node = ft_lstnew(line);
	if (!node)
		error_exit("Error: malloc failed.");
	ft_lstadd_back(info->head, node);
	(*info->rows)++;
}

char	**read_map(int fd_map, int *rows, int *cols, t_list **head)
{
	char		*line;
	int			checker[256];
	t_map_info	info;

	*rows = 0;
	*cols = 0;
	init_checker(checker, 256);
	info.rows = rows;
	info.cols = cols;
	info.checker = checker;
	info.head = head;
	line = get_next_line(fd_map);
	while (line != NULL)
	{
		process_map_line(line, &info);
		line = get_next_line(fd_map);
	}
	check_itens(checker, rows);
	return (list_matrix(*head, *rows));
}
