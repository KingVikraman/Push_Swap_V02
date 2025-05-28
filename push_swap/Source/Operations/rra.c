/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:35:23 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 15:35:26 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	rra(t_push_swap *data, int print);

void	rra(t_push_swap *data, int print)
{
	int	i;
	int	temp;

	if (data->a.top < 1)
		return ;
	temp = data->a.numbers[0];
	i = 0;
	while (i < data->a.top)
	{
		data->a.numbers[i] = data->a.numbers[i + 1];
		i++;
	}
	data->a.numbers[data->a.top] = temp;
	if (print)
		ft_putstr_fd("rra\n", 1);
}
