/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:31:24 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/09 16:55:18 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/inc/libft.h"
# include <sys/time.h>
# include <math.h>

typedef struct s_map_info
{
	int		*rows;
	int		*cols;
	int		*checker;
	t_list	**head;
}	t_map_info;

int		is_c_valid(char c);
void	init_checker(int *checker, int size);
void	free_list(t_list **head);

char	**read_map(int fd_map, int *rows, int *cols, t_list **head);

void	parse_and_validate_map(int fd_map);

char	*error_exit(char *message);
int		is_space(char c);
void	free_array(char **arr);

#endif
