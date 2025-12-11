/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:31:30 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/10 11:15:51 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char *av[])
{
	int		fd_map;

	if (ac == 2)
	{
		fd_map = open(av[1], O_RDONLY);
		if (fd_map < 0)
			error_exit("Error: no such file or directory");
		parse_and_validate_map(fd_map);
		close(fd_map);
	}
	else
		error_exit("Error: no map file provided.");
	return (0);
}
