/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:35:01 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 17:35:06 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	move_to_top(t_push_swap *data, int min_pos);
void	move_to_top_a(t_push_swap *data, int index);
void	exec_double_rotate(t_push_swap *data, t_move *move);
void	exec_single_rotate_a(t_push_swap *data, t_move *move);
void	exec_single_rotate_b(t_push_swap *data, t_move *move);

void	move_to_top(t_push_swap *data, int min_pos)
{
	int	rotations;

	rotations = get_rotation_count(&data->a, min_pos);
	while (rotations > 0)
	{
		ra(data, 1);
		rotations--;
	}
	while (rotations < 0)
	{
		rra(data, 1);
		rotations++;
	}
}

void	move_to_top_a(t_push_swap *data, int index)
{
	int	size;
	int	target_value;

	size = stack_size(data->a);
	target_value = data->a.numbers[index];
	if (index >= size / 2)
	{
		while (data->a.numbers[data->a.top] != target_value)
			rra(data, 1);
	}
	else
	{
		while (data->a.numbers[data->a.top] != target_value)
			ra(data, 1);
	}
}

void	exec_double_rotate(t_push_swap *data, t_move *move)
{
	while (move->rot_a > 0 && move->rot_b > 0)
	{
		rr(data);
		move->rot_a--;
		move->rot_b--;
	}
	while (move->rot_a < 0 && move->rot_b < 0)
	{
		rrr(data);
		move->rot_a++;
		move->rot_b++;
	}
}

void	exec_single_rotate_a(t_push_swap *data, t_move *move)
{
	while (move->rot_a > 0)
	{
		ra(data, 1);
		move->rot_a--;
	}
	while (move->rot_a < 0)
	{
		rra(data, 1);
		move->rot_a++;
	}
}

void	exec_single_rotate_b(t_push_swap *data, t_move *move)
{
	while (move->rot_b > 0)
	{
		rb(data, 1);
		move->rot_b--;
	}
	while (move->rot_b < 0)
	{
		rrb(data, 1);
		move->rot_b++;
	}
}
