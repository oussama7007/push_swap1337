/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:58:00 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/12 15:58:19 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    
    if(ac < 2)
        return(0);
    a = parse_input(ac, av);
    b = NULL;
    if(!a)
        return(handle_error(&a, &b));
    if(sort_stack(&a, &b) == 1)
        return(handle_error(&a, &b));
    clean_stacks(&a, &b);
    return(0);
}
