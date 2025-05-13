/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:00 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/13 18:44:10 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"


void	index_stack(t_stack *a);


void	index_stack(t_stack *a)
{
	int	*sorted;
	int	size;
	int	i;
	int	j;

	size = a->top + 1;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return ;

	// Copy values from a->numbers to sorted
	i = 0;
	while (i < size)
	{
		sorted[i] = a->numbers[i];
		i++;
	}

	// Bubble sort using only while
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
			{
				int tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}

	// Replace original values with indexes
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (a->numbers[i] == sorted[j])
			{
				a->numbers[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}

