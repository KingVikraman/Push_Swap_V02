/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:11:25 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/05 21:57:00 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../Includes/push_swap.h"

void	sort_five(t_push_swap *data)
{
	while (stack_size(data->a) > 3)
	{
		int index = find_lowest_index(data->a); // You’ll write this
		rra(data, index);             			// ra/rra until it’s on top
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
