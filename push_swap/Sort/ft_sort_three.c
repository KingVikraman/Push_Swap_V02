/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:11:15 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/05 20:30:41 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../Includes/push_swap.h"

void	sort_three(t_push_swap *data)
{
	int top;
	int mid;
	int bottom;
	
	top = data->a.numbers[data->a.top];
	mid = data->a.numbers[data->a.top - 1];
	bottom = data->a.numbers[data->a.top - 2];

	if (top > mid && mid < bottom && top < bottom)
		sa(data);

	else if (top > mid && mid > bottom)
	{
		sa(data);
		rra(data);
	}

	else if (top > mid && mid < bottom && top > bottom)
		ra(data);
	
	else if (top < mid && mid > bottom && top < bottom)
	{
		sa(data);
		ra(data);
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(data);
	
}