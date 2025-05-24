#include <stdio.h>
#include <limits.h>

typedef struct s_stack {
    int *numbers;
    int size;
} t_stack;

typedef struct s_push_swap {
    t_stack a;
    t_stack b;
} t_push_swap;


#define TEST1 "\n==== TEST 1: Insert 25 in [10, 30, 20, 50] ====\n"


// ===== YOUR FUNCTION =====
int find_min_position(t_stack *a)
{
    if (!a || !a->numbers || a->size <= 0)
    {
        printf("Error: Invalid stack\n");
        return -1;
    }

    int min_pos = 0;
    int min_value = a->numbers[0];
    int i = 1;  // Start comparing from second element

    while (i < a->size)
    {
        if (a->numbers[i] < min_value)
        {
            min_value = a->numbers[i];
            min_pos = i;
        }
        i++;
    }
    return min_pos;
}

// ===== TARGET POSITION FINDER =====
int find_target_position(t_push_swap *data, int num)
{
    if (!data || !data->a.numbers || data->a.size <= 0)
    {
        printf("Error: Stack A is invalid\n");
        return 0;
    }

    int i = 0;
    int pos = -1;
    int min_greater = INT_MAX;

    printf("\n🔍 Finding position for %d in stack A: [", num);
    int j = 0;
    while (j < data->a.size)
    {
        printf("%d ", data->a.numbers[j]);
        j++;
    }
    printf("]\n");

    while (i < data->a.size)
    {
        printf("  Comparing %d: ", data->a.numbers[i]);

        if (data->a.numbers[i] > num)
        {
            printf("> %d (candidate)", num);
            if (data->a.numbers[i] < min_greater)
            {
                min_greater = data->a.numbers[i];
                pos = i;
                printf(" → NEW BEST POSITION at index %d", i);
            }
        }
        else 
            printf("<= %d (ignored)", num);
        printf("\n");
        i++;
    }

    if (pos == -1)
    {
        pos = find_min_position(&data->a);
        printf("No number > %d found. Inserting after minimum (%d at position %d)\n", 
               num, data->a.numbers[pos], pos);
    }
    else
    {
        printf("Best position: index %d (before %d)\n", pos, data->a.numbers[pos]);
    }

    return pos;
}

// ===== MAIN TEST FUNCTION =====
int main()
{
    t_push_swap data;

    // Test Case 1: Normal insertion
    int arr1[] = {10, 30, 20, 50};
    data.a.numbers = arr1;
    data.a.size = 4;
    printf("%s",TEST1);
    int pos1 = find_target_position(&data, 25);
    printf("Final position: %d\n", pos1);

    // Test Case 2: All numbers smaller (fallback to min)
    int arr2[] = {10, 20, 30};
    data.a.numbers = arr2;
    data.a.size = 3;
    printf("\n==== TEST 2: Insert 60 in [10, 20, 30] ====\n");
    int pos2 = find_target_position(&data, 60);
    printf("Final position: %d\n", pos2);

    // Test Case 3: Empty stack (error handling)
    t_stack empty = {NULL, 0};
    data.a = empty;
    printf("\n==== TEST 3: Empty stack ====\n");
    int pos3 = find_target_position(&data, 10);

    return 0;
}