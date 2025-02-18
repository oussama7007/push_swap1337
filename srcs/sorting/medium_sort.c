/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:03:32 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/18 06:43:24 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void add_index(t_stack **a)
{
    int i = 0;
    int count = 0;
    t_stack *tmp;
    t_stack *first;
    tmp = *a;
    first = *a;
    while(tmp)
    {
        *a = first;   
        int value = tmp->value;
        while(i < stack_size(*a))
        {
            *a = (*a)->next;
            if(value > (*a)->value)
            {
                count++;
            }
            i++;   
        }
        tmp->index = count;
        tmp = tmp->next;
        count = 0;
    }
}
