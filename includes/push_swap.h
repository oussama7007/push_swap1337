/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:29:47 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/21 06:29:56 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/libft.h"

// *** Handle errors-free ***
t_stack	*parse_input(int ac, char **av);
void	free_split(char **split);
t_stack	*parse_input(int ac, char **av);

// *** Linked list utils ***
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
int		stack_min(t_stack *stack);
int		sort_stack(t_stack **a, t_stack **b);
int		handle_error(t_stack **a, t_stack **b);
void	clean_and_exit(t_stack **a, t_stack **b, int exit_code);

// *** Algorithms ***
int		sort_stack(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	push_smallest_to_b(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	push_max_to_a(t_stack **a, t_stack **b);
void	sort_medium(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b);
int		find_index(int *sorted_arr, int size, int value);
void	assign_indexes(t_stack **stack);
void	insertion_sort(int *arr, int len);
int		get_range(int size);
int		find_max_index_position(t_stack *b);

// *** Utils ***
int		sort_stack(t_stack **a, t_stack **b);
int		stack_min(t_stack *stack);
void	clean_stacks(t_stack **a, t_stack **b);
void	quick_sort(t_stack **a, t_stack **b);
int		find_pivot(t_stack *stack);
int		check_duplicates(t_stack *stack, int num);
int		is_valid_int(char *str);
int		is_number(char *str);

// *** Commands ***
void	push_b(t_stack **b, t_stack **a);
void	push_a(t_stack **a, t_stack **b);
void	swap_b(t_stack **b);
void	swap_a(t_stack **a);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_ab(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_ab(t_stack **a, t_stack **b);

#endif
