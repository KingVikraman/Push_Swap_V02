#include <stdio.h>

int ft_abs(int num)
{
    return (num < 0) ? -num : num;
}

int calculate_cost(int a_rot, int b_rot)
{
    int abs_a = ft_abs(a_rot);
    int abs_b = ft_abs(b_rot);
    if ((a_rot >= 0 && b_rot >= 0) || (a_rot < 0 && b_rot < 0)) {
        return (abs_a > abs_b) ? abs_a : abs_b; // Same direction: max cost
    }
    return abs_a + abs_b; // Opposite directions: sum cost
}

int main()
{
    // Test Case 1: Same direction (both positive)
    int cost1 = calculate_cost(3, 2);
    printf("Cost for (3, 2): %d\n", cost1); // Output: 3

    // Test Case 2: Same direction (both negative)
    int cost2 = calculate_cost(-1, -4);
    printf("Cost for (-1, -4): %d\n", cost2); // Output: 4

    // Test Case 3: Opposite directions (positive + negative)
    int cost3 = calculate_cost(3, -2);
    printf("Cost for (3, -2): %d\n", cost3); // Output: 5

    // Test Case 4: Opposite directions (negative + positive)
    int cost4 = calculate_cost(-5, 1);
    printf("Cost for (-5, 1): %d\n", cost4); // Output: 6

    return 0;
}