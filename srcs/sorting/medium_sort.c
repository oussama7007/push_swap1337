/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:03:32 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/26 05:14:30 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
		values[i++] = tmp->value;
		tmp = tmp->next;
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

static void	handel_push(int *i, int range, t_stack **a, t_stack **b)
{
	int	current_index;

	current_index = (*a)->index;
	if (current_index <= *i)
	{
		push_b(b, a);
		(*i)++;
	}
	else if (current_index <= *i + range)
	{
		push_b(b, a);
		rotate_b(b);
		(*i)++;
	}
	else
		rotate_a(a);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int	i;
	int	size;
	int	range;

	i = 0;
	size = stack_size(*a);
	range = get_range(size);
	if (check_reverse_sorted(size, *a))
	{
		while (size > 0)
		{
			hendel_nearly_reverse(a, b, &i, range);
			size = stack_size(*a);
		}
		return ;
	}
	while (size > 0)
	{
		handel_push(&i, range, a, b);
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
