/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:29:47 by oait-si-          #+#    #+#             */
/*   Updated: 2025/01/30 18:03:22 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

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
//*** Algorithms ***


//*** Commands ***
void    push_b(t_stack **b, t_stack **a);
void    push_a(t_stack **a, t_stack **b);
void    swap_b(t_stack **b);
void     swap_a(t_stack **a);



// push_swap/
// ├── includes/
// │   └── push_swap.h        # Header file for function declarations and includes
// ├── srcs/
// │   ├── main.c             # Main program logic
// │   ├── parsing.c          # Input parsing and validation
// │   ├── operations/        # Folder for stack operations
// │   │   ├── swap.c         # sa, sb, ss
// │   │   ├── push.c         # pa, pb
// │   │   ├── rotate.c       # ra, rb, rr
// │   │   └── reverse_rotate.c # rra, rrb, rrr
// │   ├── sorting/           # Folder for sorting algorithms
// │   │   ├── small_sort.c   # Sorting for 3 or fewer numbers
// │   │   ├── medium_sort.c  # Sorting for 5 or fewer numbers
// │   │   └── large_sort.c   # Sorting for larger numbers (e.g., 100 or 500)
// │   ├── utils/             # Utility functions
// │   │   ├── stack_utils.c  # Stack manipulation helpers
// │   │   ├── error_utils.c  # Error handling
// │   │   └── print_utils.c  # Printing stacks or operations (for debugging)
// │   └── Makefile           # Compilation rules
// ├── libft/                 # Optional: Include your libft library here
// │   ├── Makefile
// │   ├── includes/
// │   └── srcs/
// └── README.md              # Project documentation

#endif