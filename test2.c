/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 03:17:56 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/14 03:56:03 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void     insertion_sort(int *arr, int len)
{
    int i = 1;
    while (i < len)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        i++;
    }
}
int main()
{
    int arr[] = {9,9,0,8,9};
    int len = sizeof(arr)/sizeof(int);
    insertion_sort(arr, len);
    int i = 0;
    while (i < len)
    {
        printf("%d\n", arr[i++]);
    }
    return 0;
}