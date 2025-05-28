/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:01:01 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 18:01:03 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int		stack_size(t_stack a);
void	sort_two(t_push_swap *data);
void	sort_five(t_push_swap *data);
void	sort_three(t_push_swap *data);
int		find_lowest_index(t_push_swap *data);

int	stack_size(t_stack a)
{
	return (a.top + 1);
}

void	sort_five(t_push_swap *data)
{
	int	index;

	while (stack_size(data->a) > 3)
	{
		index = find_lowest_index(data);
		move_to_top_a(data, index);
		pb(data);
	}
	sort_three(data);
	pa(data);
	pa(data);
}

int	find_lowest_index(t_push_swap *data)
{
	int	i;
	int	min;
	int	index;

	i = data->a.top;
	min = data->a.numbers[i];
	index = i;
	while (i >= 0)
	{
		if (data->a.numbers[i] < min)
		{
			min = data->a.numbers[i];
			index = i;
		}
		i--;
	}
	return (index);
}

void	sort_three(t_push_swap *data)
{
	int	top;
	int	mid;
	int	bottom;

	top = data->a.numbers[data->a.top];
	mid = data->a.numbers[data->a.top - 1];
	bottom = data->a.numbers[data->a.top - 2];
	if (top > mid && mid < bottom && top < bottom)
		sa(data);
	else if (top > mid && mid > bottom)
	{
		sa(data);
		rra(data, 1);
	}
	else if (top > mid && mid < bottom && top > bottom)
		ra(data, 1);
	else if (top < mid && mid > bottom && top < bottom)
	{
		rra(data, 1);
		sa(data);
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(data, 0);
}

void	sort_two(t_push_swap *data)
{
	if (data->a.numbers[data->a.top] > data->a.numbers[data->a.top - 1])
		sa(data);
}
