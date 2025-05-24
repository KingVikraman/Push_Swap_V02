#include <stdio.h>
#include "../Includes/push_swap.h"

// typedef struct s_stack {
//     int *numbers;
//     int size;
// } t_stack;

int find_min_position(t_stack *a)
{
    if (!a || !a->numbers || a->size <= 0) {
        printf("Error: Invalid stack\n");
        return -1;
    }

    int min_pos = 0;
    int min_value = a->numbers[0];
    int i = 1;  // Start comparing from second element

    while (i < a->size) {
        if (a->numbers[i] < min_value) {
            min_value = a->numbers[i];
            min_pos = i;
        }
        i++;
    }
    return min_pos;
}

void print_stack(t_stack *stack, const char *name)
{
    printf("%s stack (%d elements): [", name, stack->size);
    int j = 0;
    while (j < stack->size) {
        printf("%d", stack->numbers[j]);
        if (j < stack->size - 1) printf(", ");
        j++;
    }
    printf("]\n");
}

int main(void)
{
    // Test case 1: Normal case
    int arr1[] = {5, 2, 8, 1, 4};
    t_stack stack1 = {arr1, sizeof(arr1)/sizeof(arr1[0])};
    
    print_stack(&stack1, "Test 1");
    int pos1 = find_min_position(&stack1);
    printf("Min position: %d (value: %d)\n\n", pos1, stack1.numbers[pos1]);

    // Test case 2: All identical elements
    int arr2[] = {7, 7, 7, 7};
    t_stack stack2 = {arr2, sizeof(arr2)/sizeof(arr2[0])};
    
    print_stack(&stack2, "Test 2");
    int pos2 = find_min_position(&stack2);
    printf("Min position: %d (value: %d)\n\n", pos2, stack2.numbers[pos2]);

    // Test case 3: Negative numbers
    int arr3[] = {-5, -10, -3, -8};
    t_stack stack3 = {arr3, sizeof(arr3)/sizeof(arr3[0])};
    
    print_stack(&stack3, "Test 3");
    int pos3 = find_min_position(&stack3);
    printf("Min position: %d (value: %d)\n\n", pos3, stack3.numbers[pos3]);

    // Test case 4: Large stack
    int arr4[1000];
    int k = 0;
    while (k < 1000) {
        arr4[k] = 1000 - k;  // Creates numbers from 1000 down to 1
        k++;
    }
    t_stack stack4 = {arr4, 1000};
    
    printf("Testing large stack (first 5 elements shown)...\n");
    printf("First Five elements: [%d, %d, %d, %d, %d, ...]\n", 
           arr4[0], arr4[1], arr4[2], arr4[3], arr4[4]);
    int pos4 = find_min_position(&stack4);
    printf("Smallest position: %d (value: %d)\n\n", pos4, stack4.numbers[pos4]);

    return 0;
}