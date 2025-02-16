/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:49 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/16 15:29:36 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



int is_valid_int(char *str)
{
    long num = ft_atoi(str);
    if(num < INT_MIN || num > INT_MAX)
        return 0;
    return 1;
}
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
        char **split = ft_split(av[i], ' ');
        int j = 0;
        while (split[j])
        {
            if(!is_number(split[j]) || !is_valid_int(split[j]))
            {
                free_split(split);
                free_stack(stack);
                return NULL;
            }
  
            num = ft_atoi(split[j]);
            if (!check_duplicates(stack, num))
            {
                free_split(split);
                free_stack(stack);
                return NULL;
            }
            ft_lstadd_back(&stack, ft_lstnew(num));
        }
        free_split(split);
        i++;
    }
    return stack;
}