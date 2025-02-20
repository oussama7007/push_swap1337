/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:03:32 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/20 03:37:56 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_index(int *sorted_arr, int size, int value)
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

static int	get_range(int size)
{
	if (size <= 100)
		return (15);
	else
		return (42);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int	i;
	int	size;
	int	range;

	i = 0;
	size = stack_size(*a);
	range = get_range(size);
	while (size > 0)
	{
		int current_index = (*a)->index;
		if (current_index <= i)
		{
			push_b(b, a);
			i++;
		}
		else if (current_index <= i + range)
		{
			push_b(b, a);
			rotate_b(b);
			i++;
		}
		else
			rotate_a(a);
		size = stack_size(*a);
	}
}

static int	find_max_index_position(t_stack *b)
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

void	push_max_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		int max_pos = find_max_index_position(*b);
		int b_size = stack_size(*b);
		if (max_pos <= b_size / 2)
		{
			while (max_pos-- > 0)
				rotate_b(b);
		}
		else
		{
			max_pos = b_size - max_pos;
			while (max_pos-- > 0)
				reverse_rotate_b(b);
		}
		push_a(a, b);
	}
}

void	sort_medium(t_stack **a, t_stack **b)
{
	assign_indexes(a);
	push_to_b(a, b);
	push_max_to_a(a, b);
}
