/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:27:06 by ingrid            #+#    #+#             */
/*   Updated: 2025/12/13 14:27:26 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_c_valid(char c)
{
	if (ft_strchr("01PEC", c) != NULL)
		return (1);
	else
		return (0);
}

void	init_checker(int *checker, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		checker[i] = 0;
		i++;
	}
}

void	free_list(t_list **head)
{
	t_list	*temp;

	if (!head)
		return ;
	while (*head)
	{
		temp = (*head)->next;
		free((*head)->content);
		free(*head);
		*head = temp;
	}
}
