/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:49 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/21 06:14:12 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	process_elements(char *str, t_stack **stack)
{
	int		num;
	t_stack	*new;

	if (!is_number(str) || !is_valid_int(str))
		return (0);
	num = ft_atoi(str);
	if (check_duplicates(*stack, num))
		return (0);
	new = ft_lstnew(num);
	if (!new)
		return (0);
	ft_lstadd_back(stack, new);
	return (1);
}

static void	clean_stack_split(t_stack *stack, char **str)
{
	free_split(str);
	free_stack(stack);
}

t_stack	*parse_input(int ac, char **av)
{
	t_stack	*stack;
	int		i;
	char	**split;
	int		j;

	stack = NULL;
	i = 0;
	while (++i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (NULL);
		j = 0;
		while (split[j])
		{
			if (process_elements(split[j], &stack) == 0)
			{
				clean_stack_split(stack, split);
				return (NULL);
			}
			j++;
		}
		free_split(split);
	}
	return (stack);
}
