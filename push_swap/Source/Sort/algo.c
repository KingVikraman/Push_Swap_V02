/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:03:49 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/16 22:03:59 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

 #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack {
    int *numbers;
    int size;
    int top; // typically top = size - 1
} t_stack;

typedef struct s_push_swap {
    t_stack a;
    t_stack b;
} t_push_swap;

typedef struct s_move {
    int cost;
    int rot_a;
    int rot_b;
} t_move;

// Utility swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Absolute value function
int ft_abs(int num) {
    return (num < 0) ? -num : num;
}

// Bubble sort function for indexing - reimplemented with while loops
void bubble_sort(int *arr, int size) {
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

// Index the stack numbers according to sorted order
void index_stack(t_stack *a) {
    int *sorted = malloc(sizeof(int) * a->size);
    int *copy = malloc(sizeof(int) * a->size);
    if (!sorted || !copy) {
        perror("malloc failed");
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
    // Assign indices based on sorted array - handle duplicates by first match
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

// Returns the number of bits required to represent max number
int get_max_bits(t_stack *stack) {
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

// For demonstration, define ra, rb, rra, rrb, pa, pb, rr, rrr as stubs (user to replace)
void ra(t_push_swap *data) {
    // Rotate stack a upwards
    int first = data->a.numbers[0];
    int i = 0;
    while (i < data->a.size - 1) {
        data->a.numbers[i] = data->a.numbers[i + 1];
        i++;
    }
    data->a.numbers[data->a.size - 1] = first;
    printf("ra\n");
}

void rb(t_push_swap *data) {
    int first = data->b.numbers[0];
    int i = 0;
    while (i < data->b.size - 1) {
        data->b.numbers[i] = data->b.numbers[i + 1];
        i++;
    }
    data->b.numbers[data->b.size - 1] = first;
    printf("rb\n");
}

void rra(t_push_swap *data) {
    int last = data->a.numbers[data->a.size - 1];
    int i = data->a.size - 1;
    while (i > 0) {
        data->a.numbers[i] = data->a.numbers[i - 1];
        i--;
    }
    data->a.numbers[0] = last;
    printf("rra\n");
}

void rrb(t_push_swap *data) {
    int last = data->b.numbers[data->b.size - 1];
    int i = data->b.size -1;
    while (i > 0) {
        data->b.numbers[i] = data->b.numbers[i - 1];
        i--;
    }
    data->b.numbers[0] = last;
    printf("rrb\n");
}

void pa(t_push_swap *data) {
    // Push from b to a
    if (data->b.size <= 0)
        return;

    data->a.numbers = realloc(data->a.numbers, sizeof(int) * (data->a.size + 1));
    int i = data->a.size;
    while (i > 0) {
        data->a.numbers[i] = data->a.numbers[i - 1];
        i--;
    }
    data->a.numbers[0] = data->b.numbers[0];
    data->a.size++;

    i = 0;
    while (i < data->b.size - 1) {
        data->b.numbers[i] = data->b.numbers[i + 1];
        i++;
    }
    data->b.size--;
    data->b.numbers = realloc(data->b.numbers, sizeof(int) * data->b.size);
    printf("pa\n");
}

void pb(t_push_swap *data) {
    // Push from a to b
    if (data->a.size <= 0)
        return;

    data->b.numbers = realloc(data->b.numbers, sizeof(int) * (data->b.size + 1));
    int i = data->b.size;
    while (i > 0) {
        data->b.numbers[i] = data->b.numbers[i - 1];
        i--;
    }
    data->b.numbers[0] = data->a.numbers[0];
    data->b.size++;

    i = 0;
    while (i < data->a.size - 1) {
        data->a.numbers[i] = data->a.numbers[i + 1];
        i++;
    }
    data->a.size--;
    data->a.numbers = realloc(data->a.numbers, sizeof(int) * data->a.size);
    printf("pb\n");
}

void rr(t_push_swap *data) {
    ra(data);
    rb(data);
    printf("rr\n");
}

void rrr(t_push_swap *data) {
    rra(data);
    rrb(data);
    printf("rrr\n");
}

// Helper: find_min_position - position of smallest element in stack a
int find_min_position(t_stack *a) {
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

// Helper: get_rotation_count - to bring position pos to top of stack s
int get_rotation_count(t_stack *s, int pos) {
    int half = s->size / 2;
    if (pos <= half)
        return pos; // rotate up pos times
    else
        return pos - s->size; // negative means rotate down (reverse rotate)
}

// Helper: find_target_position - find index in a where num from b fits in order
int find_target_position(t_push_swap *data, int num) {
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

// Calculate cost of combined rotations in a and b stacks
int calculate_cost(int a_rot, int b_rot) {
    int abs_a = ft_abs(a_rot);
    int abs_b = ft_abs(b_rot);
    if ((a_rot >= 0 && b_rot >= 0) || (a_rot < 0 && b_rot < 0)) {
        return (abs_a > abs_b) ? abs_a : abs_b;
    }
    return abs_a + abs_b;
}

// Find the cheapest move to push one element from b to a minimizing rotations
t_move find_cheapest_move(t_push_swap *data) {
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

// Execute rotations and push based on cheapest move
void execute_cheapest_move(t_push_swap *data, t_move move) {
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

// Move the smallest element in a to the top by rotating stack a
void move_to_top_a(t_push_swap *data, int min_pos) {
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

// The main sorting algorithm for large input set
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
    move_to_top_a(data, min_pos);
}

// Simple test runner
int main(void) {
    int nums[] = {5, 2, 9, 1, 6, 3};
    t_push_swap ps;
    ps.a.size = 6;
    ps.a.numbers = malloc(sizeof(int) * ps.a.size);
    int i = 0;
    while (i < ps.a.size) {
        ps.a.numbers[i] = nums[i];
        i++;
    }
    ps.b.size = 0;
    ps.b.numbers = malloc(sizeof(int) * 0);

    printf("Before sorting:\n");
    i = 0;
    while (i < ps.a.size) {
        printf("%d ", ps.a.numbers[i]);
        i++;
    }
    printf("\n");

    sort_large(&ps);

    printf("After sorting:\n");
    i = 0;
    while (i < ps.a.size) {
        printf("%d ", ps.a.numbers[i]);
        i++;
    }
    printf("\n");

    free(ps.a.numbers);
    free(ps.b.numbers);
    return 0;
}

