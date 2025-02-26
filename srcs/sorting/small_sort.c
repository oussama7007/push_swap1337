/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:00:00 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/26 02:43:44 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(a);
	else if (first > second && second > third)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a);
}

void	push_smallest_to_b(t_stack **a, t_stack **b)
{
	int		min_value;
	t_stack	*tmp;
	int		min_index;
	int		size;

	if (!*a)
		return ;
	min_value = stack_min(*a);
	tmp = *a;
	min_index = 0;
	size = stack_size(*a);
	while (tmp && tmp->value != min_value)
	{
		min_index++;
		tmp = tmp->next;
	}
	while ((*a)->value != min_value)
	{
		if (min_index <= size / 2)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
	push_b(b, a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next || !(*a)->next->next || !(*a)->next->next->next)
		return ;
	push_smallest_to_b(a, b);
	sort_three(a);
	push_a(a, b);
	if ((*a)->value > (*a)->next->value)
		rotate_a(a);
	if (!is_sorted(*a))
		rotate_a(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	push_smallest_to_b(a, b);
	push_smallest_to_b(a, b);
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
}
