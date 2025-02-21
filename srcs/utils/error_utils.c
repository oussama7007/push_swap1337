/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:34:46 by oait-si-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/20 03:33:04 by oait-si-         ###   ########.fr       */
=======
/*   Updated: 2025/02/21 02:00:52 by oait-si-         ###   ########.fr       */
>>>>>>> well done
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	handle_error(t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	clean_stacks(a, b);
	return (1);
}

void	clean_stacks(t_stack **a, t_stack **b)
{
	free_stack(*a);
	free_stack(*b);
	*a = NULL;
	*b = NULL;
}
