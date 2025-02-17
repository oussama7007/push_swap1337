/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:54:55 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/17 05:02:11 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_word_count(char *str, char c)
{
    int i;
    int count;
    int in_word = 0;
    
    i = 0;
    count = 0;
    while (str[i])
    {
        if(str[i] != c && in_word == 0)
        {
            in_word = 1;
            count++;
        }
        else if(str[i] == c)
            in_word = 0;
        i++;
    }
    return count;
}

static char *ft_worddup(int start, int i, char *str)
{
    char *new;
    int len;
    int j;

    j = 0;
    len = i - start;
    new = malloc((len + 1) * sizeof(char));
    if(!new)
        return NULL;
    while (j < len)
    {
        new[j++] = str[start++];
    }
    new[j] = '\0';
    return new;
}

static void free_buffer(char **new, int index)
{
    while (index > 0)
        free(new[--index]);
    free(new); 
}

char **fill_result(char *str, char c, char **new)
{
    int start;
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        while(str[i] && str[i] == c)
            i++;
        if (str[i] == '\0') 
            break;
        start = i;
        while(str[i] && str[i] != c)
            i++;
        if(start < i)
        {
            new[j] = ft_worddup(start, i, str);
            if(!new[j])
            {
                free_buffer(new , j);
                return NULL;
            }
            j++;
        }
    }
    new[j] = NULL; 
    return new;
}

char **ft_split(char *str, char c)
{
    if(!str)
        return NULL;
    int count_word = ft_word_count(str, c);
    char **new = (char **)malloc((count_word + 1) * sizeof(char *));
    if(!new)
        return NULL;
    char **result = fill_result(str, c, new);
    return result;
}