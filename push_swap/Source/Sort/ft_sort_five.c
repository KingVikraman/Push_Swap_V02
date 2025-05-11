/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:11:25 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/11 20:50:55 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void 	move_to_top_a(t_push_swap *data, int index);
int		find_lowest_index(t_push_swap *data);
void	sort_five(t_push_swap *data);
int		stack_size(t_stack a);



void	sort_five(t_push_swap *data)
{
	while (stack_size(data->a) > 3)
	{
		int index = find_lowest_index(data);	// You’ll write this
		move_to_top_a(data, index);								// ra/rra until it’s on top
		pb(data);                               // Push to b
	}
	sort_three(data);                          // Sort 3 in A
	pa(data);
	pa(data);
}

int		stack_size(t_stack a)
{
	return a.top + 1;
}

int		find_lowest_index(t_push_swap *data)
{
	int i = data->a.top;
	int min = data->a.numbers[i];
	int index = i;

	while (i >= 0)
	{
		if (data->a.numbers[i] < min)
		{
			min = data->a.numbers[i];
			index = i;
		}
		i--;
	}
	return index;
}

// void	move_to_top_a(t_push_swap *data, int index)
// {
// 	int size;
// 	int top;

// 	size = stack_size(data->a);
// 	top = data->a.top;

// 	if (index >= size / 2)
// 	{
// 		while (data->a.top != index)
// 		{
// 			printf("%d,%d\n", data->a.top, index);
// 			rra(data);
// 		}
// 	}
// 	else
// 	{
// 		while (data->a.top != index)
// 			ra(data);
// 	}
// }


void	move_to_top_a(t_push_swap *data, int index)
{
	if (index < 0 || index > data->a.top)
		return ;
	
	int steps;

	if (index <= data->a.top / 2)
	{
		steps = index;
		while (steps--)
			ra(data);
	}
	else
	{
		steps = data->a.top - index;
		while (steps--)
			rra(data);
	}
}


