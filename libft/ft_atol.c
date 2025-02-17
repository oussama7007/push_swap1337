/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:53:13 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/17 05:01:40 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

long ft_atol(const char *str)
{
    long result = 0;
    int i = 0;
    int sign = 1;

    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] && ft_isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (sign * result);
}

int ft_atoi(const char *str)
{
    return (int)ft_atol(str);
}