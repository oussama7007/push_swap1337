/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:01:16 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/17 04:00:09 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"
void quick_sort(t_stack **a, t_stack **b)
{
    if (!*a || !(*a)->next)
        return;

    int pivot = find_pivot(*a);
    int size = stack_size(*a);
    int i = 0;

    while (i < size)
    {
        if ((*a)->value < pivot)
            push_b(a, b);
        else
            rotate_a(a);
        i++;
    }

    int b_size = stack_size(*b);
    while (b_size--)
        push_a(a, b);

    quick_sort(a, b);
    quick_sort(a, b);
}

int find_pivot(t_stack *stack)
{
    if (!stack)
        return 0; // or handle the empty stack case appropriately

    while (stack->next)
    {
        stack = stack->next;
    }
    return stack->value; // Choose the last element as pivot
}