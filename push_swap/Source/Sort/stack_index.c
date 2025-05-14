/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:00 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/14 14:39:12 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"


void swap(int *a, int *b);
void index_stack(t_stack *a);
void radix_sort(t_push_swap *data);
void smart_merge(t_push_swap *data);
void msb_pass(t_push_swap *data, int bit);
void lsb_pass(t_push_swap *data, int bit);
int find_position(t_stack stack, int num);
int find_closest_to_top(t_push_swap *data);
void rotate_to_top_b(t_push_swap *data, int num);




void index_stack(t_stack *a)
{
    int *sorted;
    int size = a->top + 1;
    sorted = malloc(sizeof(int) * size);
    if (!sorted) return;

    // Copy values (no for loop)  
    int i = 0;
    while (i < size)
    {
        sorted[i] = a->numbers[i];
        i++;
    }

    // Bubble sort (no for loop)  
    i = 0;
    while (i < size - 1)
    {
        int j = 0;
        while (j < size - i - 1)
        {
            if (sorted[j] > sorted[j + 1])
                swap(&sorted[j], &sorted[j + 1]);
            j++;
        }
        i++;
    }

    // Replace with indexes (no for loop)  
    i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
        {
            if (a->numbers[i] == sorted[j])
            {
                a->numbers[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
    free(sorted);
}

void radix_sort(t_push_swap *data)
{
    int max_bits = 0;
    int max_num = data->a.numbers[data->a.top];
    while ((max_num >> max_bits) != 0)
        max_bits++;

    int bit = 0;
    while (bit < max_bits)
    {
        if (bit % 2 == 0)
            lsb_pass(data, bit);
        else
            msb_pass(data, bit);
        bit++;
    }
    smart_merge(data);
}

void lsb_pass(t_push_swap *data, int bit)
{
    int len = data->a.top + 1;
    while (len--) {
        if ((data->a.numbers[0] >> bit) & 1)
            ra(data);
        else
            pb(data);
    }
}

void msb_pass(t_push_swap *data, int bit)
{
    int i = data->a.top;
    while (i >= 0) {
        if ((data->a.numbers[data->a.top] >> bit) & 1)
            rra(data);
        else
            pb(data);
        i--;
    }
}


void smart_merge(t_push_swap *data)
{
    while (data->b.top >= 0) {
        int closest = find_closest_to_top(data);
        rotate_to_top_b(data, closest);
        pa(data);
    }
}

int find_closest_to_top(t_push_swap *data)
{
    int i = data->b.top;
    int closest = data->b.numbers[i];
    while (i >= 0)
    {
        if (data->b.numbers[i] > closest)
            closest = data->b.numbers[i];
        i--;
    }
    return closest;  
}  

void rotate_to_top_b(t_push_swap *data, int num)
{
    int pos = find_position(data->b, num);
    int mid = data->b.top / 2;
    if (pos > mid)
    {
        while (data->b.numbers[data->b.top] != num)
            rrb(data);
    }
    else
    {
        while (data->b.numbers[data->b.top] != num)
            rb(data);
    }
}

int find_position(t_stack stack, int num)
{
    int i = 0;
    while (i <= stack.top) {  // Loop until we reach the top of the stack
        if (stack.numbers[i] == num) {
            return i;  // Return the position if found
        }
        i++;
    }
    return -1;  // Return -1 if the number is not found
}

void swap(int *a, int *b)
{
    int temp = *a;  // Store value at address `a`
    *a = *b;        // Overwrite value at `a` with value at `b`
    *b = temp;      // Put original `a` value into `b`
}