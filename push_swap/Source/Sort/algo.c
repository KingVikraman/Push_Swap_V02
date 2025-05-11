/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:24:28 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/11 21:07:40 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

bool 	is_empty(t_stack s);
void	chunk_sort(t_push_swap *data);
int 	find_max_position(t_stack *s);
void 	smart_rotate_b(t_push_swap *data, int pos);
int     find_in_chunk(t_stack a, int chunk_start, int chunk_end);
void    bubble_sort(int *arr, int size);


void	chunk_sort(t_push_swap *data)
{
    int chunk_size = data->a.size <= 100 ? 15 : 30;
    int sorted[data->a.size];
    int i = 0;

    // Create sorted reference array
    while (i <= data->a.top)
    {
        sorted[i] = data->a.numbers[i];
        i++;
    }
    bubble_sort(sorted, data->a.size);

    // Push chunks to B
    i = 0;
    while (i < data->a.size)
    {
        int chunk_end = (i + chunk_size < data->a.size) ? i + chunk_size : data->a.size;
        int chunk_start_val = sorted[i];
        int chunk_end_val = sorted[chunk_end - 1];

        while (1)
        {
            int pos = find_in_chunk(data->a, chunk_start_val, chunk_end_val);
            if (pos == -1)
                break;
            
            move_to_top_a(data, pos);
            pb(data);
        }
        i += chunk_size;
    }

    // Rebuild stack A
    while (!is_empty(data->b))
    {
        int max_pos = find_max_position(&data->b);
        smart_rotate_b(data, max_pos);
        pa(data);
    }
}


int		find_in_chunk(t_stack a, int chunk_start, int chunk_end)
{
    int best_pos = -1;
    int best_diff = INT_MAX;
    int i = a.top;

    while (i >= 0)
    {
        if (a.numbers[i] >= chunk_start && a.numbers[i] <= chunk_end)
        {
            int diff = abs((chunk_start + chunk_end) / 2 - a.numbers[i]);
            if (diff < best_diff)
            {
                best_diff = diff;
                best_pos = i;
            }
        }
        i--;
    }
    return best_pos;
}

void	smart_rotate_b(t_push_swap *data, int pos)
{
    int steps;
    
    if (pos <= data->b.top / 2)
    {
        steps = pos;
        while (steps--)
            rb(data);
    }
    else
    {
        steps = data->b.top - pos;
        while (steps--)
            rrb(data);
    }
}

void bubble_sort(int *arr, int size) 
{
    int i = 0;
    while (i < size - 1) 
    {
        int j = 0;
        while (j < size - i - 1) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
	
bool	is_empty(t_stack s)
{
    return (s.top == -1);
}

int		find_max_position(t_stack *s)
{
    int max_pos = 0;
    int i = 1;
    
    while (i <= s->top)
    {
        if (s->numbers[i] > s->numbers[max_pos])
            max_pos = i;
        i++;
    }
    return max_pos;
}