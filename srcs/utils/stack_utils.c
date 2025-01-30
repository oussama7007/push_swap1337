/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:28:53 by oait-si-          #+#    #+#             */
/*   Updated: 2025/01/29 01:07:54 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap/includes/push_swap.h"
 
int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void    free_stack(t_stack *stack)
{
    t_stack *tmp;
    while(stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp); 
    }
}

int     stack_size(t_stack *stack)
{
    int size;

    size = 0;
    while(stack)
    {
        size++;
        stack = stack->next;
    }
    return(size);
}
t_stack *stack_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}