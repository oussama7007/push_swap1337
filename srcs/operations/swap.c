/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:09:21 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/26 05:17:05 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	swap_a(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
