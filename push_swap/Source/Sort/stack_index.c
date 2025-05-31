/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:18:52 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/29 21:18:54 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void		index_stack(t_stack *a);
void		bubble_sort(int *arr, int size);
static void	index_numbers(t_stack *a, int *sorted, int *copy);
static void	alloc_and_copy(t_stack *a, int **sorted, int **copy);
void		update_cheapest(t_push_swap *data, t_move *cheapest, int i);

void	index_stack(t_stack *a)
{
	int	*sorted;
	int	*copy;

	alloc_and_copy(a, &sorted, &copy);
	bubble_sort(sorted, a->size);
	index_numbers(a, sorted, copy);
	free(sorted);
	free(copy);
}

static void	index_numbers(t_stack *a, int *sorted, int *copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (copy[i] == sorted[j])
			{
				a->numbers[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	alloc_and_copy(t_stack *a, int **sorted, int **copy)
{
	int	i;

	*sorted = malloc(sizeof(int) * a->size);
	*copy = malloc(sizeof(int) * a->size);
	if (!*sorted || !*copy)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < a->size)
	{
		(*copy)[i] = a->numbers[i];
		(*sorted)[i] = a->numbers[i];
		i++;
	}
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	swapped;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

void	update_cheapest(t_push_swap *data, t_move *cheapest, int i)
{
	int	b_rot;
	int	a_rot;
	int	cost;
	int	target_pos;

	target_pos = find_target_position(data, data->b.numbers[i]);
	a_rot = get_rotation_count(&data->a, target_pos);
	b_rot = get_rotation_count(&data->b, i);
	cost = calculate_cost(a_rot, b_rot);
	if (cost < cheapest->cost)
	{
		cheapest->cost = cost;
		cheapest->rot_a = a_rot;
		cheapest->rot_b = b_rot;
	}
}
