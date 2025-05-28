/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:30:33 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 15:30:40 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	pa(t_push_swap *data);

void	pa(t_push_swap *data)
{
	if (data->b.top == -1)
		return ;
	data->a.top++;
	data->a.size++;
	data->a.numbers[data->a.top] = data->b.numbers[data->b.top];
	data->b.top--;
	data->b.size--;
	ft_putstr_fd("pa\n", 1);
}
