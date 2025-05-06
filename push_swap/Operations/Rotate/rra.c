	/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:15:02 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/04 17:14:29 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void	rra(t_push_swap *data);

void	rra(t_push_swap *data)
{
	int i;
	int temp;

	if (data->a.top < 1)
		return ;

	temp = data->a.numbers[0];

	i = 0;
	while(i < data->a.top)
	{
		data->a.numbers[i] = data->a.numbers[i + 1];
		i++;
	}
	data->a.numbers[data->a.top] = temp;
	ft_putstr_fd("rra\n", 1);
}


