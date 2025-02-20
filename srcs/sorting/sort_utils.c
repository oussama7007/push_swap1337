/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 03:34:28 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/20 03:35:52 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    insertion_sort(int *arr, int len)
{
    int i = 0;
    int key;
    int j;
    while(i < len)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+ 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        i++;
    }
}

void    assign_indexes(t_stack **stack)
{
    int i;
    int size = stack_size(*stack);
    int *values = malloc(sizeof(int) *size);
    
    if(!values)
        return ;
    
    i = 0;
    t_stack *tmp = *stack;
    while (i < size)
    {
        values[i] = tmp->value;
        tmp = tmp->next;
        i++;
    }
    insertion_sort(values, size);
    
    tmp = *stack;
    while(tmp)
    {
        tmp->index = find_index(values, size, tmp->value);
        tmp = tmp->next;
    }
    free(values);
}
