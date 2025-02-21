/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:15:55 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/21 06:26:06 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_index(int *sorted_arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (value == sorted_arr[i])
			return (i);
		i++;
	}
	return (-1);
}

int	get_range(int size)
{
	if (size <= 100)
		return (15);
	else
		return (42);
}

int	find_max_index_position(t_stack *b)
{
	int	max_index;
	int	position;
	int	max_pos;

	max_index = INT_MIN;
	position = 0;
	max_pos = 0;
	while (b)
	{
		if (b->index > max_index)
		{
			max_index = b->index;
			max_pos = position;
		}
		position++;
		b = b->next;
	}
	return (max_pos);
}
