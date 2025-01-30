/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:09:21 by oait-si-          #+#    #+#             */
/*   Updated: 2025/01/30 17:54:07 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap/includes/push_swap.h"

void     swap_a(t_stack **a)
{
    t_stack *tmp;
    
    if(!*a || !(*a)->next)
        return;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = (*a)->next;
    (*a)->next = tmp;
    write(1,"sa\n", 3); 
}
void    swap_b(t_stack **b)
{
    t_stack *tmp;
    
    if(!*b || !(*b)->next)
        return;
    tmp = (*b);
    (*b) = (*b)->next;
    tmp->next = (*b)->next;
    (*b)->next = tmp;
    write(1,"sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    t_stack *mp;
    
    if(!*b || !(*b)->next || !*a || !(*a)->next)
        return;
    tmp = (*b);
    (*b) = (*b)->next;
    tmp->next = (*b)->next;
    (*b)->next = tmp;
    mp = *a;
    *a = (*a)->next;
    mp->next = (*a)->next;
    (*a)->next = mp;
    write(1,"ss\n", 3);
}