/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:58:00 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/02 23:51:17 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "/mnt/homes/oait-si-/Desktop/push__swap/includes/push_swap.h"

static void     clean_and_exit(t_stack **a, t_stack **b, int exit_code)
{
    free_stack(*a);
    free_stack(*b);
}

static int handle_error(t_stack **a, t_stack **b)
{
    write(2, "Error\n", 6);
    clean_stacks(a, b);
    return (1);   
}
   
static int    sort_stack(t_stack **a, t_stack **b)
{
    int size;

      
    size = stack_size(*a);
    if (!*a || !(*a)->next)
        return (0);
    if(is_sorted(*a))
        return 0;
    else if(size == 2)
        swap_a(a);
    else if (size == 3)
        sort_three(a);
    else if(size == 5)
        sort_five(a, b);
    else 
        radix_sort(a, b);
    if (!is_sorted(*a))
        return (1);
    return (0);
}
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


