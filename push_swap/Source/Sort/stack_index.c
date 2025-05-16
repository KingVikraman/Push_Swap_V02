/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:00 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/16 12:46:13 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"


void swap(int *a, int *b);
void index_stack(t_stack *a);
int find_max_position(t_stack stack);
void optimized_sort(t_push_swap *data);
int find_position(t_stack stack, int num);
void rotate_to_top_b(t_push_swap *data, int num);
void rotate_to_top_a(t_push_swap *data, int num);
int find_closest_in_range(t_stack stack, int start, int end);





void index_stack(t_stack *a) {
    int *sorted = malloc(sizeof(int) * (a->top + 1));
    if (!sorted) return;
    
    // Copy values
    int i = 0;
    while (i <= a->top) {
        sorted[i] = a->numbers[i];
        i++;
    }
    
    // Bubble sort without for
    i = 0;
    while (i <= a->top) {
        int j = 0;
        while (j < a->top - i) {
            if (sorted[j] > sorted[j+1])
                swap(&sorted[j], &sorted[j+1]);
            j++;
        }
        i++;
    }
    
    // Replace with indexes
    i = 0;
    while (i <= a->top) {
        int j = 0;
        while (j <= a->top) {
            if (a->numbers[i] == sorted[j]) {
                a->numbers[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
    free(sorted);
}

// For-loop-free optimized sort
void optimized_sort(t_push_swap *data) {
    int chunk_size = (data->a.top + 1) / 5;
    int chunk_start = 0;
    
    // Phase 1: Push chunks to B
    while (chunk_start <= data->a.top) {
        int chunk_end = chunk_start + chunk_size;
        while (1) {
            int closest = find_closest_in_range(data->a, chunk_start, chunk_end);
            if (closest == -1) break;
            rotate_to_top_a(data, closest);
            pb(data);
            if (data->b.top > 0 && data->b.numbers[0] < data->b.numbers[1])
                rb(data);
        }
        chunk_start += chunk_size;
    }
    
    // Phase 2: Merge back to A
    while (data->b.top >= 0) {
        int max_pos = find_max_position(data->b);
        rotate_to_top_b(data, data->b.numbers[max_pos]);
        pa(data);
    }
}

// For-loop-free helpers
int find_closest_in_range(t_stack stack, int start, int end) {
    int closest_pos = -1;
    int min_dist = INT_MAX;
    int i = 0;
    
    while (i <= stack.top) {
        if (stack.numbers[i] >= start && stack.numbers[i] <= end) {
            int dist = abs(i - stack.top / 2);
            if (dist < min_dist) {
                min_dist = dist;
                closest_pos = i;
            }
        }
        i++;
    }
    return closest_pos;
}

int find_max_position(t_stack stack) {
    int max_pos = 0;
    int i = 1;
    
    while (i <= stack.top) {
        if (stack.numbers[i] > stack.numbers[max_pos])
            max_pos = i;
        i++;
    }
    return max_pos;
}

// Rotation functions (unchanged)
void rotate_to_top_a(t_push_swap *data, int index) {
    int target = data->a.numbers[index];
    int size = data->a.top + 1;
    
    if (index > size / 2) {
        while (data->a.numbers[data->a.top] != target)
            rra(data);
    } else {
        while (data->a.numbers[data->a.top] != target)
            ra(data);
    }
}

void rotate_to_top_b(t_push_swap *data, int num) {
    int pos = find_position(data->b, num);
    int size = data->b.top + 1;
    
    if (pos > size / 2) {
        while (data->b.numbers[data->b.top] != num)
            rrb(data);
    } else {
        while (data->b.numbers[data->b.top] != num)
            rb(data);
    }
}

int find_position(t_stack stack, int num) {
    int i = 0;
    while (i <= stack.top) {
        if (stack.numbers[i] == num)
            return i;
        i++;
    }
    return -1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}