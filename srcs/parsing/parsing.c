/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:49 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/20 04:18:24 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_int(char *str)
{
	long	num;

	num = ft_atol(str);
	return (num >= INT_MIN && num <= INT_MAX);
}

int	is_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack, int num)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
static void free_stack_split(char **split, t_stack *stack)
{
    free_split(split);
	free_stack(stack);
}

t_stack	*parse_input(int ac, char **av)
{
	t_stack	*stack;
	int		i;
	int		num;
	char	**split;
	int		j;
	t_stack	*new;

	stack = NULL;
	i = 0;
	while (i++ < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (NULL);
		j = -1;
		while (split[++j])
		{
			if (!is_number(split[j]) || !is_valid_int(split[j]))
			{
				
				return (NULL);
			}
			num = ft_atoi(split[j]);
			if (check_duplicates(stack, num))
			{
				free_stack_split(split,stack);
				return (NULL);
			}
			new = ft_lstnew(num);
			if (!new)
			{
		        free_stack_split(split,stack);
				return (NULL);
			}
			ft_lstadd_back(&stack, new);
		}
		free_split(split);
	}
	return (stack);
}
