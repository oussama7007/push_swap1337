/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:46:20 by oait-si-          #+#    #+#             */
/*   Updated: 2025/01/30 17:44:45 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap/includes/push_swap.h"

void    push_a(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    
    if(!*a || !*b)
        return;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    write(1,"pa\n", 3);
}

void    push_b(t_stack **b, t_stack **a)
{
    t_stack *tmp;
    if(!*a || !*b)
        return;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    write(1, "pb\n", 3);
}