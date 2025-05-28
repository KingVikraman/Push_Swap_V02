/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:00 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 13:47:55 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void index_stack(t_stack *a);
void bubble_sort(int *arr, int size);




void index_stack(t_stack *a)
{
    int *sorted = malloc(sizeof(int) * a->size);
    int *copy = malloc(sizeof(int) * a->size);
    if (!sorted || !copy) {
        perror("Error\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (i < a->size) {
        copy[i] = a->numbers[i];
        sorted[i] = a->numbers[i];
        i++;
    }
    bubble_sort(sorted, a->size);
    i = 0;
    while (i < a->size) {
        int j = 0;
        while (j < a->size) {
            if (copy[i] == sorted[j]) {
                a->numbers[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
    free(sorted);
    free(copy);
}

void bubble_sort(int *arr, int size)
{
    int i = 0;
    int swapped;
    while (i < size - 1) {
        swapped = 0;
        int j = 0;
        while (j < size - 1 - i) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
            j++;
        }
        if (!swapped)
            break;
        i++;
    }
}
