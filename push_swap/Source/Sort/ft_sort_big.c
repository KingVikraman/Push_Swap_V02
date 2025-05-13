/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:00:45 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/13 17:04:52 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// #include "../../Includes/push_swap.h"


// int	find_highest_index(t_stack *stack);
// void	sort_big(t_push_swap *data, int count);

// void	sort_big(t_push_swap *data, int count)
// {
// 	int i = 0;
// 	int chunk_size;
// 	int current_chunk_max;
// 	int pushed = 0;

// 	// Determine chunk size based on input size
// 	if (count <= 100)
// 		chunk_size = 15; // Tweak this if needed
// 	else
// 		chunk_size = 30;

// 	current_chunk_max = chunk_size;

// 	while (pushed < count)
// 	{
// 		if (data->a.numbers[data->a.top] <= current_chunk_max)
// 		{
// 			pb(data);
// 			pushed++;
// 			if (data->b.top > 0 && data->b.numbers[data->b.top] < current_chunk_max - (chunk_size / 2))
// 				rb(data); // Optional optimization
// 		}
// 		else
// 			ra(data); // Rotate A to find correct chunk element
// 		if (pushed == current_chunk_max)
// 			current_chunk_max += chunk_size;
// 	}

// 	// Now move back from B to A in sorted order
// 	while (data->b.top >= 0)
// 	{
// 		int max_index = find_highest_index(&data->b);
// 		move_to_top_b(data, max_index);
// 		pa(data);
// 	}
// }


// int	find_highest_index(t_stack *stack)
// {
// 	int i = stack->top;
// 	int max = stack->numbers[i];
// 	int index = i;

// 	while (i >= 0)
// 	{
// 		if (stack->numbers[i] > max)
// 		{
// 			max = stack->numbers[i];
// 			index = i;
// 		}
// 		i--;
// 	}
// 	return index;
// }

