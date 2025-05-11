/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:44:06 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/11 21:20:12 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void	index_stack(t_push_swap *data);
//static void	copy_array(int *dest, int *src, int size);
//static void	apply_indexing(t_stack *stack, int *sorted, int size);

// void	index_stack(t_push_swap *data)
// {
// 	int *sorted;
// 	int size = data->a.size;

// 	if (!data || data->a.size <= 0)
// 		return ;
	
// 	sorted = malloc(sizeof(int) * size);
// 	if (!sorted)
// 		return;

// 	copy_array(sorted, data->a.numbers, size);
// 	bubble_sort(sorted, size);
// 	apply_indexing(&data->a, sorted, size);

// 	free(sorted);
// }

void index_stack(t_push_swap *data) 
{
    if (!data || data->a.size <= 0) 
        return;

    int *sorted = malloc(data->a.size * sizeof(int));
    int *original = malloc(data->a.size * sizeof(int));
    int i = 0;

    // Backup original numbers using while
    while (i < data->a.size) 
    {
        original[i] = data->a.numbers[i];
        sorted[i] = data->a.numbers[i];
        i++;
    }

    // Sort the copied array (bubble_sort with while loops)
    bubble_sort(sorted, data->a.size);

    // Replace stack numbers with their indexes (while loop)
    i = 0;
    while (i < data->a.size) 
    {
        int j = 0;
        while (j < data->a.size) 
        {
            if (original[i] == sorted[j]) 
            {
                data->a.numbers[i] = j; // Assign index
                break;
            }
            j++;
        }
        i++;
    }

    free(sorted);
    free(original);
}

// static void	copy_array(int *dest, int *src, int size)
// {
// 	int i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// }


// static void	apply_indexing(t_stack *stack, int *sorted, int size)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (stack->numbers[i] == sorted[j])
// 			{
// 				stack->numbers[i] = j;
// 				break;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
//}