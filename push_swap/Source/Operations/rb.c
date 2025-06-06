/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:34:44 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 15:34:51 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	rb(t_push_swap *data, int print);

void	rb(t_push_swap *data, int print)
{
	int	i;
	int	temp;

	if (data->b.top < 1)
		return ;
	temp = data->b.numbers[data->b.top];
	i = data->b.top;
	while (i > 0)
	{
		data->b.numbers[i] = data->b.numbers[i - 1];
		i--;
	}
	data->b.numbers[0] = temp;
	if (print)
		ft_putstr_fd("rb\n", 1);
}
