/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:34:46 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/25 02:59:13 by oait-si-         ###   ########.fr       */
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

// int check_for_empty_arg(int ac, char **av)
// {
// 	int is_empty = 0;
// 	int i = 0;
// 	int j = 1;
// 	while(j < ac)
// 	{
// 		i = 0;
// 		is_empty = 0;
// 		while(av[j][i])
// 		{
// 			if(av[j][i] != ' ')
// 				is_empty = 1;
// 			if(av[j][i + 1] == '\0' && is_empty == 0)
// 				return 0;
// 			i++;
// 		}
// 		j++;
// 	}
// 	return 1;
// }
int check_for_empty_arg(int ac, char **av)
{
    int j = 1;

    while (j < ac)
    {
        int i = 0;
        int is_empty = 0;

        // Handle empty string arguments (e.g., "")
        if (av[j][0] == '\0')
            return (0);

        while (av[j][i])
        {
            if (av[j][i] != ' ')
                is_empty = 1;
            i++;
        }

        // Check if the entire argument was spaces
        if (is_empty == 0)
            return (0);

        j++;
    }
    return (1);
}