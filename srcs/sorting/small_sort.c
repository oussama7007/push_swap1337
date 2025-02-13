/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:00:00 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/13 03:53:06 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void sort_three(t_stack **a)
{
    int first;
    int second;
    int third;

    if (!*a || !((*a)->next) || !((*a)->next->next) || (*a)->next->next->next)
        return;
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

void    push_smallet_to_b(t_stack **a, t_stack **b)
{
    int min_value;
    t_stack *min_node;
    
    min_node =* a;
    min_value = min_node->value;

    while(min_node)
    {
        if(min_value > min_node->value)
            min_value = min_node->value;
        min_node = min_node->next;
    }
    while((*a)->value != min_value)
        rotate_a(a);
    push_b(a, b);
}
void    sort_five(t_stack **a, t_stack **b)
{
    
}