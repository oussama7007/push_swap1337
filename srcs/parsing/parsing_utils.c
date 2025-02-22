/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:32:47 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/22 08:44:29 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
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

int	is_valid_int(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num >= INT_MIN && num <= INT_MAX)
		return (1);
	return (0);
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
