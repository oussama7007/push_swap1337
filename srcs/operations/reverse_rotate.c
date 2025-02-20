/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:46:27 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/20 03:45:08 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *stack;
	prev->next = NULL;
	*stack = last;
}

void	reverse_rotate_a(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	if (!*b || !(*b)->next || !*a || !(*a)->next)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
