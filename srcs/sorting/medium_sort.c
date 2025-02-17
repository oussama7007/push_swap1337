/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:03:32 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/17 05:40:56 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_medium(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int i;
    int middle = size / 2;

    // Push smaller half to stack b
    i = 0;
    while (i < middle)
    {
        push_smallest_to_b(a, b);
        i++;
    }

    // Sort remaining elements in stack a
    if (size - middle <= 3)
        sort_three(a);
    else
        quick_sort(a, b);

    // Push back elements from b to a
    while (*b)
        push_a(a, b);
}