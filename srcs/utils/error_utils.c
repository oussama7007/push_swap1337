/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:34:46 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/09 10:36:20 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int handle_error(t_stack **a, t_stack **b)
{
    write(2, "Error\n", 6);
    clean_stacks(a, b);
    return (1);   
}
void     clean_and_exit(t_stack **a, t_stack **b, int exit_code)
{
    free_stack(*a);
    free_stack(*b);
}