/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:46:20 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/26 05:16:04 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	push_a(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push(a, b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **b, t_stack **a)
{
	if (!*a)
		return ;
	push(b, a);
	write(1, "pb\n", 3);
}
