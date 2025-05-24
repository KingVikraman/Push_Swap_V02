#include <stdio.h>
#include <stdlib.h>


typedef struct s_stack
{
    int *data;   // Array to hold stack elements
    int size;    // Current number of elements
    int capacity; // Maximum capacity (optional)
} t_stack;

int get_rotation_count(t_stack *s, int pos)
{
    int half = s->size / 2;
    if (pos <= half)
        return pos;          // Rotate up (e.g., 2 → rotate twice)
    else
        return pos - s->size; // Negative means reverse rotate (e.g., -2 → reverse twice)
}


int main()
{
    t_stack stack;
    stack.size = 10;  // Let's say the stack has 10 elements (indices 0-9)
    
    // Test Case 1: Rotate up (pos in first half)
    int pos1 = 2;
    int rotations1 = get_rotation_count(&stack, pos1);
    printf("Rotations needed for pos %d: %d (rotate up %d times)\n", pos1, rotations1, rotations1);

    // Test Case 2: Reverse rotate (pos in second half)
    int pos2 = 8;
    int rotations2 = get_rotation_count(&stack, pos2);
    printf("Rotations needed for pos %d: %d (reverse rotate %d times)\n", pos2, rotations2, -rotations2);

    return 0;
}