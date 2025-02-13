/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:55:28 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/12 18:10:04 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_stack **stack, t_stack *new)
{
    t_stack *temp;

    if (!*stack)
    {
        *stack = new;
        return;
    }
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}