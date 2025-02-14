/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:44:23 by oait-si-          #+#    #+#             */
/*   Updated: 2025/02/14 03:08:07 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void swap(int *x, int *y);
void quicksort(int arr[], int len );
void quicksort_recursion(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int a[] = {4,5,2,1,7};
    int len = sizeof(a)/sizeof(a[0]);
    
    quicksort(a, len);
    int i = 0;
    while(i < len )
    {
        printf("%d\n", a[i++]);
    }
}
void    swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quicksort(int arr[], int len)
{
    quicksort_recursion(arr, 0, len);
}
void quicksort_recursion(int arr[], int low, int high)
{
    if(low < high)
    {
            int pivot_index = partition(arr, low, high);
        quicksort_recursion(arr, low, pivot_index - 1);
        quicksort_recursion(arr, pivot_index + 1, high);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot_value = arr[high];
    int i = low;
    int j = low;
    while (j < high)
    {
        if(arr[j] <= pivot_value)
        {
            swap(&arr[i], &arr[j]);
            //printf("* ");
            i++;
        }
        j++;
    }
    swap(&arr[i], &arr[high]);
    //printf("* ");
    return i;
}

