/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:30:49 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/12 21:49:41 by ingrid           ###   ########.fr       */
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

static void	check_itens(t_map map)
{
	if (map.rows == 0)
		error_exit("Error: empty map.");
	if (map.checker['P'] != 1)
		error_exit("Error: map must contain exactly one player (P).");
	if (map.checker['E'] != 1)
		error_exit("Error: map must contain exactly one exit (E).");
	if (map.checker['C'] < 1)
		error_exit("Error: map must contain at least one collectible (C).");
}

static char	**to_strv(t_list *head, int rows)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		error_exit("Error: malloc failed.");
	i = 0;
	while (head)
	{
		map[i] = head->content;
		head = head->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void	process_map_line(char *line, t_map *map)
{
	t_list	*node;
	int		len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (map->rows == 0)
		map->cols = len;
	else if (map->cols != len)
		error_exit("Error: invalid map (not rectangular).");
	count_map_chars(line, map->checker);
	node = ft_lstnew(line);
	if (!node)
		error_exit("Error: malloc failed.");
	ft_lstadd_back(&map->head, node);
	map->rows++;
}

void	read_map(int fd_map, t_map *map)
{
	char	*line;

	map->rows = 0;
	map->cols = 0;
	map->head = NULL;
	init_checker(map->checker, 256);
	line = get_next_line(fd_map);
	while (line != NULL)
	{
		process_map_line(line, map);
		line = get_next_line(fd_map);
	}
	check_itens(*map);
	map->grid = to_strv(map->head, map->rows);
	free_list(&map->head);
	map->head = NULL;
}
