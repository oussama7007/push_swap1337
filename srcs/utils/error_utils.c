/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:34:46 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/26 05:13:10 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	check_for_empty_arg(int ac, char **av)
{
	int	j;
	int	i;
	int	is_empty;

	j = 1;
	while (j < ac)
	{
		i = 0;
		is_empty = 0;
		if (av[j][0] == '\0')
			return (0);
		while (av[j][i])
		{
			if (av[j][i] != ' ')
				is_empty = 1;
			i++;
		}
		if (is_empty == 0)
			return (0);
		j++;
	}
	return (1);
}

int	check_reverse_sorted(int size, t_stack *a)
{
	t_stack	*tmp;
	int		count;

	tmp = a;
	count = 0;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			count++;
		tmp = tmp->next;
	}
	return (count > size / 2);
}

void	hendel_nearly_reverse(t_stack **a, t_stack **b, int *i, int range)
{
	int	current_index;

	current_index = (*a)->index;
	if (current_index <= *i)
	{
		push_b(b, a);
		(*i)++;
	}
	else if (current_index <= *i + range)
	{
		push_b(b, a);
		rotate_b(b);
		(*i)++;
	}
	else
		reverse_rotate_a(a);
}
