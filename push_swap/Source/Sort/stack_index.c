/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:00 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/27 19:07:45 by rvikrama         ###   ########.fr       */
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

void sort_large(t_push_swap *data)
{
    // print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');
    // printf("_______________________\n");

    //Step 1: Push all but top 3 to B
    while (data->a.top + 1 > 3)
    {
        pb(data);
       // print_stack_a(&data->a, 'a');
	  //  print_stack_b(&data->b, 'b');
       // printf("_______________________\n");
    }
    // Step 2: Sort the remaining 3 elements in A
    sort_three(data);  // You must implement this (for 3 values)


    // Step 3: While B is not empty, move elements back to A using cheapest move
    while (data->b.top >= 0)
    {
        //fix here...
        t_move best = find_cheapest_move(data);
        execute_cheapest_move(data, best);
        //
        //print_stack_a(&data->a, 'a');
	    //print_stack_b(&data->b, 'b');
       // printf("_______________________\n");
    }

    // Step 4: Final rotation to put smallest element at the top
   // printf("FINAL\n");
    int min_pos = find_min_position(&data->a);
    move_to_top(data, min_pos);
   //  printf("HERE\n");
   // print_stack_a(&data->a, 'a');
   // print_stack_b(&data->b, 'b');
   // printf("_______________________\n");
}

int find_min_position(t_stack *a)
{
    int max_pos = 0;
    int i = 1;
    while (i < a->size)
    {
       if (a->numbers[i] < a->numbers[max_pos])
            max_pos = i;
        i++;
    }
    return max_pos;
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
//Here got problem, raja babi pls fix it!!
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
        ra(data, 1);
        move.rot_a--;
    }
    while (move.rot_a < 0) {
        rra(data, 1);
        move.rot_a++;
    }
    while (move.rot_b > 0) {
        rb(data,1);
        move.rot_b--;
    }
    while (move.rot_b < 0) {
        rrb(data,1);
        move.rot_b++;
    }
    pa(data);
}



void move_to_top(t_push_swap *data, int min_pos)
{
    int rotations = get_rotation_count(&data->a, min_pos);
    while (rotations > 0) {
        ra(data, 1);
        rotations--;
    }
    while (rotations < 0) {
        rra(data, 1);
        rotations++;
    }
}
// Helper functions
int get_rotation_count(t_stack *s, int pos)
{
    pos++;
    int half = (int)ceil((double)s->size / 2.0);
    if (pos >= half)
        return s->size - pos; 
    else
        return -1 * pos; 
}

int find_target_position(t_push_swap *data, int num)
{
    int i = 0;
    int pos = -1;
    int min_greater = INT_MAX;
    while (i < data->a.size) {
        if (data->a.numbers[i] > num && data->a.numbers[i] < min_greater)
        {
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
    return (num < 0) ? -num : num;
}


/*
1) Operation Modifications

a) pa, pb 
  - Added missing `size++` and `size--` adjustments.
b) ra, rb, rra, rrb       
  - Added a boolean parameter to disable printing.
  - Printing should be disabled when called via `rr` or `rrr`

2) main()
  - data->b.size must be initialized to zero at the start

3) get_rotation_count()
  a) You're comparing s->size (counting positions from 1) to pos (zero-based index).
     To get the correct amount of rotation use position-count
     pos++ to align it with position s->size
  b) To determine the correct half of the stack,  round to the nearest larger integer
  c) Change condition from if (pos <= half) to if (pos >= half)
  d) Amend the rotation count calculation accordingly

4) find_target_position()
 - If pos == -1, it means num is the largest value and should be placed on top the smallest number in stack A.
   Use pos = find_min_position() for that.
   The code following that condition becomes unnecessary and can be removed.
*/