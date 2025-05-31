/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:54:35 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 17:54:37 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int		get_max_bits(t_stack *stack);
void	sort_large(t_push_swap *data);
int		calculate_cost(int a_rot, int b_rot);
int		get_rotation_count(t_stack *s, int pos);
void	execute_cheapest_move(t_push_swap *data, t_move move);

void	sort_large(t_push_swap *data)
{
	t_move	best;
	int		min_pos;

	index_stack(&data->a);
	while (data->a.top + 1 > 3)
	{
		pb(data);
	}
	sort_three(data);
	while (data->b.top >= 0)
	{
		best = find_cheapest_move(data);
		execute_cheapest_move(data, best);
	}
	min_pos = find_min_position(&data->a);
	move_to_top(data, min_pos);
}

void	execute_cheapest_move(t_push_swap *data, t_move move)
{
	exec_double_rotate(data, &move);
	exec_single_rotate_a(data, &move);
	exec_single_rotate_b(data, &move);
	pa(data);
}

int	get_rotation_count(t_stack *s, int pos)
{
	int	half;

	pos++;
	half = (int)ceil((double)s->size / 2.0);
	if (pos >= half)
		return (s->size - pos);
	else
		return (-1 * pos);
}

int	get_max_bits(t_stack *stack)
{
	int	max_num;
	int	i;
	int	max_bits;

	max_num = stack->numbers[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->numbers[i] > max_num)
			max_num = stack->numbers[i];
		i++;
	}
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	calculate_cost(int a_rot, int b_rot)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(a_rot);
	abs_b = ft_abs(b_rot);
	if ((a_rot >= 0 && b_rot >= 0) || (a_rot < 0 && b_rot < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		else
			return (abs_b);
	}
	return (abs_a + abs_b);
}
