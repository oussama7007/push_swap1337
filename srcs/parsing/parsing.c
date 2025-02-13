/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:49 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/10 10:19:19 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_number(char *str)
{
    int i;
    if(!str || !*str)
        return 0;
    i = 0;
    while (str[i]== '-' || str[i] == '+')
    i++;
    while (str[i])
    {
        if(!ft_isdigit(str[i]))
            return(0);
        i++;
    }
    return (1);
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
t_stack *parse_input(int ac, char **av)
{
    t_stack *stack = NULL;
    int i = 1;
    int num;

    while (i < ac)
    {
        if (!is_number(av[i]))
            return NULL;
        num = ft_atoi(av[i]);
        if (!check_duplicates(stack, num))
        {
            free_stack(stack);
            return NULL;
        }
        ft_lstadd_back(&stack, ft_lstnew(num));
        i++;
    }
    return stack;
}