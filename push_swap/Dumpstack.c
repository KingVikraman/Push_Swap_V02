// pb(data);
	// ft_putstr_fd("After pa:\n", 1);
	// print_stack_b(data);
	// print_stack(&data->a, 'a');
	// pa(data);
	// pa(data);
	// print_stack(&data->a, 'a');
	// print_stack_b(data);

	// i = 0;
	// while (i < data->count)
	// {
	//     ft_putnbr_fd(data->a.numbers[i], 1);
	//     ft_putchar_fd(' ', 1);
	//     i++;
	// }
	// ft_putchar_fd('\n', 1);


    // pb(data);
	// //ft_putstr_fd("After pb:\n", 1);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');

	// pb(data);
	// //ft_putstr_fd("After pb:\n", 1);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b,'b');

	// sb(data);
	// ft_putstr_fd("After sb:\n", 1);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b,'b');


	// data->a.numbers = malloc(sizeof(int) * data->b.size);
	// data->a.size = data->b.size;
	// data->a.top = -1;

	// print_stack(&data->a, 'a');
	// print_stack(&data->b, 'b');
	// ft_putstr_fd("before pb:\n", 1);

	// pb(data);

	// print_stack(&data->a, 'a');
	// print_stack(&data->b, 'b');
	// ft_putstr_fd("After pb:\n", 1);


	// pa(data);

	// print_stack(&data->a, 'a');
	// print_stack(&data->b, 'b');
	// ft_putstr_fd("After pa:\n", 1);


	//sa(data);
	//ft_putstr_fd("After sa:\n", 1);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');

	// while(data->a.top >= 4 )
	// {
	// 	pb(data);
	// 	print_stack_a(&data->a, 'a');
	// 	print_stack_b(&data->b, 'b');
	// }

	// ra(data);
	// rb(data);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');

	// rra(data);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');

	// ss(data);
	// //ft_putstr_fd("After sa:\n", 1);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');

	// while (data->b.top >= 0 )
	// {
	// 	pa(data);
	// 	//pa(data);
	// 	//ft_putstr_fd("After pa:\n", 1);
	// 	print_stack_a(&data->a, 'a');
	// 	print_stack_b(&data->b,'b');
	// }


	// data->error = 0;
	// i = 0;
	// while (i < count)
	// {
	// 	// data->a.numbers[i] = ft_atoi(split[i], &data->error);
	// 	data->a.numbers[count - 1 - i] = ft_atoi(split[i], &data->error);
	// 	if (data->error)
	// 		break;
	// 	i++;
	// }

	// static void init_parser(t_push_swap *data, int count)
// {
// 	data->count = count;
// 	data->error = 0;
// 	data->numbers = malloc(sizeof(int) * count);
//     if (!data->numbers)
//     data->error = 1;
// }

// t_push_swap	*parse_check(int argc, char **argv)
// {
// 	t_push_swap	*data;
// 	char		*combined;
// 	char		**split;
// 	int			i;

// 	if (argc < 2)
// 		return (NULL);

// 	combined = combine_args(argc, argv);
// 	if (!combined)
// 		return (NULL);

// 	split = ft_split(combined, ' ');
// 	free(combined);
// 	if (!split)
// 		return (NULL);

// 	data = malloc(sizeof(t_stack));
// 	if (!data)
// 		return (ft_free_split(split), NULL);

// 	data->count = 0;
// 	while (split[data->count])
// 		data->count++;

// 	data->numbers = malloc(sizeof(int) * data->count);
// 	if (!data->numbers)
// 		return (ft_free_split(split), free(data), NULL);

// 	i = -1;
// 	data->error = 0;
// 	while (++i < data->count)
// 	{
// 		data->numbers[i] = ft_atoi(split[i], &data->error);
// 		if (data->error)
// 			break ;
// 	}

// 	ft_free_split(split);
// 	return (data);
// }




// void	index_stack(t_push_swap *data);
//static void	copy_array(int *dest, int *src, int size);
//static void	apply_indexing(t_stack *stack, int *sorted, int size);

// void	index_stack(t_push_swap *data)
// {
// 	int *sorted;
// 	int size = data->a.size;

// 	if (!data || data->a.size <= 0)
// 		return ;
	
// 	sorted = malloc(sizeof(int) * size);
// 	if (!sorted)
// 		return;

// 	copy_array(sorted, data->a.numbers, size);
// 	bubble_sort(sorted, size);
// 	apply_indexing(&data->a, sorted, size);

// 	free(sorted);
// }

// void index_stack(t_push_swap *data) 
// {
//     if (!data || data->a.size <= 0) 
//         return;

//     int *sorted = malloc(data->a.size * sizeof(int));
//     int *original = malloc(data->a.size * sizeof(int));
//     int i = 0;

//     // Backup original numbers using while
//     while (i < data->a.size) 
//     {
//         original[i] = data->a.numbers[i];
//         sorted[i] = data->a.numbers[i];
//         i++;
//     }

//     // Sort the copied array (bubble_sort with while loops)
//     bubble_sort(sorted, data->a.size);

//     // Replace stack numbers with their indexes (while loop)
//     i = 0;
//     while (i < data->a.size) 
//     {
//         int j = 0;
//         while (j < data->a.size) 
//         {
//             if (original[i] == sorted[j]) 
//             {
//                 data->a.numbers[i] = j; // Assign index
//                 break;
//             }
//             j++;
//         }
//         i++;
//     }

//     free(sorted);
//     free(original);
// }

// static void	copy_array(int *dest, int *src, int size)
// {
// 	int i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// }


// static void	apply_indexing(t_stack *stack, int *sorted, int size)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (stack->numbers[i] == sorted[j])
// 			{
// 				stack->numbers[i] = j;
// 				break;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
//}


// #include "../../Includes/push_swap.h"

// void use_advanced_sort(t_push_swap *data, int count);
// void restore_original_values(t_push_swap *data, int *sorted_original);

// // void 	use_advanced_sort(t_push_swap *data, int count)
// // {
// // 	index_stack(data);
// // 	chunk_sort(data);
// // 	return ;

	 
// // }

// // void use_advanced_sort(t_push_swap *data, int count)
// // {
// //     if (!data || data->error)  // Safety check
// //         return;

// //     index_stack(data);         // Ensure numbers are indexed (0 to N-1)
    
// //     if (count <= 100)
// //         chunk_sort(data);  // 15-sized chunks for 100 numbers
// //     else
// //         chunk_sort(data);  // 30-sized chunks for 500 numbers
// // }

// void use_advanced_sort(t_push_swap *data, int count) 
// {
//     if (!data || data->error || count <= 0 || count > data->a.size) 
//         return;  // Safety check

//     int *sorted_original = malloc(count * sizeof(int));  // Use count
//     int i = 0;

//     while (i < count)  // Use count as the limit
//     {
//         sorted_original[i] = data->a.numbers[i];
//         i++;
//     }

//     index_stack(data);
//     chunk_sort(data);
//     restore_original_values(data, sorted_original);

//     free(sorted_original);
// }

// void restore_original_values(t_push_swap *data, int *sorted_original) 
// {
//     int i = 0;
//     while (i <= data->a.top) 
//     {
//         data->a.numbers[i] = sorted_original[data->a.numbers[i]]; // Map index → original
//         i++;
//     }
// }




// #include "../../Includes/push_swap.h"

// bool 	is_empty(t_stack s);
// void	chunk_sort(t_push_swap *data);
// int 	find_max_position(t_stack *s);
// void 	smart_rotate_b(t_push_swap *data, int pos);
// int     find_in_chunk(t_stack a, int chunk_start, int chunk_end);
// void    bubble_sort(int *arr, int size);


// void	chunk_sort(t_push_swap *data)
// {
//     int chunk_size = data->a.size <= 100 ? 15 : 30;
//     int sorted[data->a.size];
//     int i = 0;

//     // Create sorted reference array
//     while (i <= data->a.top)
//     {
//         sorted[i] = data->a.numbers[i];
//         i++;
//     }
//     bubble_sort(sorted, data->a.size);

//     // Push chunks to B
//     i = 0;
//     while (i < data->a.size)
//     {
//         int chunk_end = (i + chunk_size < data->a.size) ? i + chunk_size : data->a.size;
//         int chunk_start_val = sorted[i];
//         int chunk_end_val = sorted[chunk_end - 1];

//         while (1)
//         {
//             int pos = find_in_chunk(data->a, chunk_start_val, chunk_end_val);
//             if (pos == -1)
//                 break;
            
//             move_to_top_a(data, pos);
//             pb(data);
//         }
//         i += chunk_size;
//     }

//     // Rebuild stack A
//     while (!is_empty(data->b))
//     {
//         int max_pos = find_max_position(&data->b);
//         smart_rotate_b(data, max_pos);
//         pa(data);
//     }
// }


// int		find_in_chunk(t_stack a, int chunk_start, int chunk_end)
// {
//     int best_pos = -1;
//     int best_diff = INT_MAX;
//     int i = a.top;

//     while (i >= 0)
//     {
//         if (a.numbers[i] >= chunk_start && a.numbers[i] <= chunk_end)
//         {
//             int diff = abs((chunk_start + chunk_end) / 2 - a.numbers[i]);
//             if (diff < best_diff)
//             {
//                 best_diff = diff;
//                 best_pos = i;
//             }
//         }
//         i--;
//     }
//     return best_pos;
// }

// void	smart_rotate_b(t_push_swap *data, int pos)
// {
//     int steps;
    
//     if (pos <= data->b.top / 2)
//     {
//         steps = pos;
//         while (steps--)
//             rb(data);
//     }
//     else
//     {
//         steps = data->b.top - pos;
//         while (steps--)
//             rrb(data);
//     }
// }

// void bubble_sort(int *arr, int size) 
// {
//     int i = 0;
//     while (i < size - 1) 
//     {
//         int j = 0;
//         while (j < size - i - 1) 
//         {
//             if (arr[j] > arr[j + 1]) 
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//             j++;
//         }
//         i++;
//     }
// }
	
// bool	is_empty(t_stack s)
// {
//     return (s.top == -1);
// }

// int		find_max_position(t_stack *s)
// {
//     int max_pos = 0;
//     int i = 1;
    
//     while (i <= s->top)
//     {
//         if (s->numbers[i] > s->numbers[max_pos])
//             max_pos = i;
//         i++;
//     }
//     return max_pos;
// }















/*********************************************************************************************** 


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
        else {
            pb(data);
            // Rotate Stack B if needed (e.g., to keep largest at top)
            if (data->b.top > 0 && data->b.numbers[0] < data->b.numbers[1])
                rb(data);
        }
    }
}

void msb_pass(t_push_swap *data, int bit)
{
    int i = data->a.top;
    while (i >= 0) {
        if ((data->a.numbers[data->a.top] >> bit) & 1)
            rra(data);
        else {
            pb(data);
            // Optional: Rotate Stack B here too
            if (data->b.top > 0 && data->b.numbers[0] < data->b.numbers[1])
                rb(data);
        }
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
*/