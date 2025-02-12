/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:00:00 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/12 18:14:25 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_three(t_stack **a)
{
    int first;
    int  second;
    int  third;
    
    if(!*a || !((*a)->next) ||((*a)->next->next))
        return;
    first = (*a)->value;
    second = (*a)->next->value;
    third = (*a)->next->next->value;

    if(first < second && second > third)
        reverse_rotate_a(a);
    else if (first > second && second > third)
    {
        swap_a(a);
        reverse_rotate_a(a);
    }
    else if (first < second && second > third)
    {
        reverse_rotate_a(a);
        swap_a(a);
    }
    else if (first > second && third > second)
        swap_a(a);
}
// static void    print_stack(t_stack *a)
// {
//     while (a)
//     {
//         printf("%d", a->value);
//         a = a->next;
//     }
//     printf("\n");
// }
// int main()
// {
//     t_stack *stack = NULL;
//     ft_lstadd_back(&stack, ft_lstnew(3));
//     ft_lstadd_back(&stack, ft_lstnew(2));
//     ft_lstadd_back(&stack, ft_lstnew(1));
//     printf("before: ");
//     print_stack(stack);
//     sort_three(&stack);
//     printf("After: ");
//     print_stack(stack);
//     clean_stacks(&stack, NULL);
// }