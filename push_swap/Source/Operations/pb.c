/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:34:05 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 15:34:17 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	pb(t_push_swap *data);

void	pb(t_push_swap *data)
{
	if (data->a.top == -1)
		return ;
	data->b.top++;
	data->b.size++;
	data->b.numbers[data->b.top] = data->a.numbers[data->a.top];
	data->a.top--;
	data->a.size--;
	ft_putstr_fd("pb\n", 1);
}
