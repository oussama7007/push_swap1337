/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:53:13 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/08 17:37:55 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int check_num(int result, char c, int sign)
{
    int test;
    
    test = result;
    result = (result * 10 + (c - 48)) * sign;
    if(result <= test)
        return 0;
    else    
        return 1;
}

int ft_atoi(char *str)
{
    int result;
    int i;
    int sign;

    while (str[i] != '\0' || str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        else 
            sign = 1;
        i++;
    }
    result = 0;
    while (str[i] || str[i] >= '0' && str[i] <= '9')
    {
        result *= 10 + (str[i] - 48);
        i++;
        if(check_num(result, str[i], sign) == 0)
            return 0;
    }
    return (sign * result);
}