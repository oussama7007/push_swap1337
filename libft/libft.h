/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:29:34 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/22 08:39:37 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}	t_stack;

void		ft_lstadd_back(t_stack **stack, t_stack *new);
t_stack		*ft_lstnew(int value);
t_stack		*stack_last(t_stack *stack);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
int			ft_isdigit(char c);
char		**ft_split(char *str, char c);

#endif
