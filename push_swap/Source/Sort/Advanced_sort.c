/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:06:28 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/11 21:17:35 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void use_advanced_sort(t_push_swap *data, int count);
void restore_original_values(t_push_swap *data, int *sorted_original);

// void 	use_advanced_sort(t_push_swap *data, int count)
// {
// 	index_stack(data);
// 	chunk_sort(data);
// 	return ;

	 
// }

// void use_advanced_sort(t_push_swap *data, int count)
// {
//     if (!data || data->error)  // Safety check
//         return;

//     index_stack(data);         // Ensure numbers are indexed (0 to N-1)
    
//     if (count <= 100)
//         chunk_sort(data);  // 15-sized chunks for 100 numbers
//     else
//         chunk_sort(data);  // 30-sized chunks for 500 numbers
// }

void use_advanced_sort(t_push_swap *data, int count) 
{
    if (!data || data->error || count <= 0 || count > data->a.size) 
        return;  // Safety check

    int *sorted_original = malloc(count * sizeof(int));  // Use count
    int i = 0;

    while (i < count)  // Use count as the limit
    {
        sorted_original[i] = data->a.numbers[i];
        i++;
    }

    index_stack(data);
    chunk_sort(data);
    restore_original_values(data, sorted_original);

    free(sorted_original);
}

void restore_original_values(t_push_swap *data, int *sorted_original) 
{
    int i = 0;
    while (i <= data->a.top) 
    {
        data->a.numbers[i] = sorted_original[data->a.numbers[i]]; // Map index → original
        i++;
    }
}