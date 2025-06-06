/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:31:11 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 14:31:26 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	ra(t_push_swap *data, int print);

void	ra(t_push_swap *data, int print)
{
	int	i;
	int	temp;

	if (data->a.top < 1)
		return ;
	temp = data->a.numbers[data->a.top];
	i = data->a.top;
	while (i > 0)
	{
		data->a.numbers[i] = data->a.numbers[i - 1];
		i--;
	}
	data->a.numbers[0] = temp;
	if (print)
	{
		ft_putstr_fd("ra\n", 1);
	}
}
