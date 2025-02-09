/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:49 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/08 22:49:49 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_number(char *str)
{
    if(ft_atoi(str) == 0)
        return 0;
    else 
        return 1;

}
int check_duplicates(t_stack *stack, int num)
{
    t_stack *tmp;
    tmp = stack;
    while(tmp)
    {
        if(tmp->value == num)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}
