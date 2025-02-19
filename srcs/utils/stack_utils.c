/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:28:53 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/19 05:29:10 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void free_stack(t_stack *stack)
{
    t_stack *tmp;

    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

int stack_size(t_stack *stack)
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

int stack_min(t_stack *stack)
{
    int min;

    if (!stack)
        return 0;
    min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}

int sort_stack(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);

    if (!*a || !(*a)->next)
        return 0;
    if (is_sorted(*a))
        return 0;
    else if (size == 2)
        swap_a(a);
    else if (size == 3)
        sort_three(a);
    else if (size == 4)
        sort_four(a, b);
    else if (size == 5)
        sort_five(a, b);
    else
        sort_medium(a, b);
    if (!is_sorted(*a))
        return 1;
    return 0;
}