/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:29:47 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/09 10:34:08 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_stack
{
    int     value;
    struct s_stack    *next;
} t_stack;

//*** Handle input ./push_swap "1 -42 1337" ***

//*** Handle errors-free ***

//*** Stack creation ***

//*** linked list utils ***
int	            is_sorted(t_stack *stack);
void            free_stack(t_stack *stack);
int             stack_size(t_stack *stack);
t_stack         *stack_last(t_stack *stack);
int             stack_min(t_stack *stack);
int    sort_stack(t_stack **a, t_stack **b);
int handle_error(t_stack **a, t_stack **b);
void     clean_and_exit(t_stack **a, t_stack **b, int exit_code);
//*** Algorithms ***

//*** utils */

//*** Commands ***
void    push_b(t_stack **b, t_stack **a);
void    push_a(t_stack **a, t_stack **b);
void    swap_b(t_stack **b);
void     swap_a(t_stack **a);



// push_swap/
// ├── includes/
// │   └── push_swap.h
// ├── srcs/
// │   ├── parsing/              # New directory for parsing
// │   │   ├── parsing.c         # Input validation and parsing
// │   │   └── parsing_utils.c   # Helper functions for parsing
// │   ├── operations/
// │   │   ├── swap.c
// │   │   ├── push.c
// │   │   ├── rotate.c
// │   │   └── reverse_rotate.c
// │   ├── sorting/
// │   │   ├── sort_utils.c      # New: Common sorting utilities
// │   │   ├── small_sort.c
// │   │   ├── medium_sort.c
// │   │   └── large_sort.c
// │   ├── utils/
// │   │   ├── stack_utils.c
// │   │   ├── error_utils.c
// │   │   └── debug_utils.c     # Renamed from print_utils.c
// │   ├── main.c
// ├── libft/
// └── makefile 
#endif