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

int 	ft_abs(int num);
void 	swap(int *a, int *b);
int 	find_min_position(t_stack *a);
t_move	find_cheapest_move(t_push_swap *data);
int 	find_target_position(t_push_swap *data, int num);


int ft_abs(int num)
{
    return (num < 0) ? -num : num;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_min_position(t_stack *a)
{
    int max_pos = 0;
    int i = 1;
    while (i < a->size)
    {
       if (a->numbers[i] < a->numbers[max_pos])
            max_pos = i;
        i++;
    }
    return max_pos;
}

t_move find_cheapest_move(t_push_swap *data)
{
    t_move cheapest = {INT_MAX, 0, 0};
    int i = 0;
    while (i < data->b.size) {
        int target_pos = find_target_position(data, data->b.numbers[i]);
        int a_rot = get_rotation_count(&data->a, target_pos);
        int b_rot = get_rotation_count(&data->b, i);
        int cost = calculate_cost(a_rot, b_rot);
        if (cost < cheapest.cost) {
            cheapest.cost = cost;
            cheapest.rot_a = a_rot;
            cheapest.rot_b = b_rot;
        }
        i++;
    }
    return cheapest;
}

int find_target_position(t_push_swap *data, int num)
{
    int i = 0;
    int pos = -1;
    int min_greater = INT_MAX;
    while (i < data->a.size) {
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
    return pos;
}