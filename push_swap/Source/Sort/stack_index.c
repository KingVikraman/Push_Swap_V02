/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:00 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/16 21:18:33 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

int ft_abs(int num);
void swap(int *a, int *b);
void index_stack(t_stack *a);
int get_max_bits(t_stack *stack);
void sort_large(t_push_swap *data);
int find_min_position(t_stack *a);
void bubble_sort(int *arr, int size);
void move_to_top(t_push_swap *data, int min_pos);
int get_rotation_count(t_stack *s, int pos);
int find_target_position(t_push_swap *data, int num);
t_move find_cheapest_move(t_push_swap *data);
void execute_cheapest_move(t_push_swap *data, t_move move);
int calculate_cost(int a_rot, int b_rot);
void align_stack_a(t_push_swap *data);




void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void index_stack(t_stack *a)
{
    int *sorted = malloc(sizeof(int) * a->size);
    int *copy = malloc(sizeof(int) * a->size);
    if (!sorted || !copy) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    // Copy original values
    int i = 0;
    while (i < a->size) {
        copy[i] = a->numbers[i];
        sorted[i] = a->numbers[i];
        i++;
    }

    // ACTUALLY CALL BUBBLE SORT HERE
    bubble_sort(sorted, a->size);

    // Assign indices based on sorted array
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

void align_stack_a(t_push_swap *data)
{
    int min_pos = find_min_position(&data->a);
    int rotations = get_rotation_count(&data->a, min_pos);
    
    while (rotations > 0) {
        ra(data);
        rotations--;
    }
    while (rotations < 0) {
        rra(data);
        rotations++;
    }
}


int get_max_bits(t_stack *stack)
{
    int max_num = stack->numbers[0];
    int i = 1;
    while (i < stack->size) {
        if (stack->numbers[i] > max_num)
            max_num = stack->numbers[i];
        i++;
    }
    int max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;
    return max_bits;
}

void sort_large(t_push_swap *data) {
    index_stack(&data->a); // replace numbers by their indices for radix sort
    int max_bits = get_max_bits(&data->a);
    int i = 0;
    while (i < max_bits) {
        int count = data->a.size;
        int j = 0;
        while (j < count) {
            if (((data->a.numbers[0] >> i) & 1) == 1) {
                ra(data);
            } else {
                pb(data);
            }
            j++;
        }
        // Push all from b back to a
        while (data->b.size > 0) {
            pa(data);
        }
        i++;
    }
    // After sorting indices, ensure smallest element is on top
    int min_pos = find_min_position(&data->a);
    move_to_top(data, min_pos);
}

int find_min_position(t_stack *a)
{
    int min_pos = 0;
    int i = 1;
    while (i < a->size) {
        if (a->numbers[i] < a->numbers[min_pos]) {
            min_pos = i;
        }
        i++;
    }
    return min_pos;
}

int calculate_cost(int a_rot, int b_rot)
{
    int abs_a = ft_abs(a_rot);
    int abs_b = ft_abs(b_rot);
    if ((a_rot >= 0 && b_rot >= 0) || (a_rot < 0 && b_rot < 0)) {
        return (abs_a > abs_b) ? abs_a : abs_b;
    }
    return abs_a + abs_b;
}

t_move find_cheapest_move(t_push_swap *data)
{
    t_move cheapest = {INT_MAX, 0, 0};
    int i = 0;
    while (i < data->b.size) {
        int target_pos = find_target_position(data, data->b.numbers[i]);
        int a_rot = get_rotation_count(&data->a, target_pos);
        int b_rot = get_rotation_count(&data->b, i);
        int cost = calculate_cost(a_rot, b_rot);
        if (cost < cheapest.cost) {
            cheapest.cost = cost;
            cheapest.rot_a = a_rot;
            cheapest.rot_b = b_rot;
        }
        i++;
    }
    return cheapest;
}
void execute_cheapest_move(t_push_swap *data, t_move move)
{
    while (move.rot_a > 0 && move.rot_b > 0) {
        rr(data);
        move.rot_a--;
        move.rot_b--;
    }
    while (move.rot_a < 0 && move.rot_b < 0) {
        rrr(data);
        move.rot_a++;
        move.rot_b++;
    }
    while (move.rot_a > 0) {
        ra(data);
        move.rot_a--;
    }
    while (move.rot_a < 0) {
        rra(data);
        move.rot_a++;
    }
    while (move.rot_b > 0) {
        rb(data);
        move.rot_b--;
    }
    while (move.rot_b < 0) {
        rrb(data);
        move.rot_b++;
    }
    pa(data);
}



void move_to_top(t_push_swap *data, int min_pos)
{
    int rotations = get_rotation_count(&data->a, min_pos);
    while (rotations > 0) {
        ra(data);
        rotations--;
    }
    while (rotations < 0) {
        rra(data);
        rotations++;
    }
}
// Helper functions
int get_rotation_count(t_stack *s, int pos)
{
    int half = s->size / 2;
    if (pos <= half)
        return pos; // rotate up pos times
    else
        return pos - s->size; // negative means rotate down (reverse rotate)
}

int find_target_position(t_push_swap *data, int num)
{
    int i = 0;
    int pos = -1;
    int min_greater = INT_MAX;
    while (i < data->a.size) {
        if (data->a.numbers[i] > num && data->a.numbers[i] < min_greater) {
            min_greater = data->a.numbers[i];
            pos = i;
        }
        i++;
    }
    if (pos == -1) {
        // no number greater, so put after min element
        pos = find_min_position(&data->a);
    }
    return pos;
}


int ft_abs(int num)
{
    if (num < 0)
        return (-num);
    return (num);
}
