/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Finding_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:44:14 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 17:44:17 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int		ft_abs(int num);
void	swap(int *a, int *b);
int		find_min_position(t_stack *a);
t_move	find_cheapest_move(t_push_swap *data);
int		find_target_position(t_push_swap *data, int num);

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	find_min_position(t_stack *a)
{
	int	max_pos;
	int	i;

	i = 1;
	max_pos = 0;
	while (i < a->size)
	{
		if (a->numbers[i] < a->numbers[max_pos])
			max_pos = i;
		i++;
	}
	return (max_pos);
}

t_move	find_cheapest_move(t_push_swap *data)
{
	t_move	cheapest;
	int		i;

	cheapest.cost = INT_MAX;
	cheapest.rot_a = 0;
	cheapest.rot_b = 0;
	i = 0;
	while (i < data->b.size)
	{
		update_cheapest(data, &cheapest, i);
		i++;
	}
	return (cheapest);
}

int	find_target_position(t_push_swap *data, int num)
{
	int	i;
	int	pos;
	int	min_greater;

	i = 0;
	pos = -1;
	min_greater = INT_MAX;
	while (i < data->a.size)
	{
		if (data->a.numbers[i] > num && data->a.numbers[i] < min_greater)
		{
			min_greater = data->a.numbers[i];
			pos = i;
		}
		i++;
	}
	if (pos == -1)
	{
		pos = find_min_position(&data->a);
	}
	return (pos);
}
