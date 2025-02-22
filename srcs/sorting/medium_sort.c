/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:03:32 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/22 16:03:09 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	insertion_sort(int *arr, int len)
{
	int	i;
	int	key;
	int	j;

	i = 0;
	while (i < len)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

void	assign_indexes(t_stack **stack)
{
	int		i;
	int		size;
	int		*values;
	t_stack	*tmp;

	size = stack_size(*stack);
	values = malloc(sizeof(int) * size);
	if (!values)
		return ;
	i = 0;
	tmp = *stack;
	while (i < size)
	{
		values[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	insertion_sort(values, size);
	tmp = *stack;
	while (tmp)
	{
		tmp->index = find_index(values, size, tmp->value);
		tmp = tmp->next;
	}
	free(values);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int		i;
	int		size;
	int		range;
	int		current_index;

	i = 0;
	size = stack_size(*a);
	range = get_range(size);
	while (size > 0)
	{
		current_index = (*a)->index;
		if (current_index <= ++i)
			push_b(b, a);
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

void	push_max_to_a(t_stack **a, t_stack **b)
{
	int	max_pos;
	int	b_size;

	while (*b)
	{
		max_pos = find_max_index_position(*b);
		b_size = stack_size(*b);
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
