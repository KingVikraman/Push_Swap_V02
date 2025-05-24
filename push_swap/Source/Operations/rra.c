/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:02:24 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/24 22:44:22 by rvikrama         ###   ########.fr       */
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
	while (i < data->a.top)
	{
		data->a.numbers[i] = data->a.numbers[i + 1];
		i++;
	}
	data->a.numbers[data->a.top] = temp;
	ft_putstr_fd("rra\n", 1);
}

// void rra(t_push_swap *data)
// {
//     int last = data->a.numbers[data->a.size - 1];
//     int i = data->a.size - 1;
//     while (i > 0) {
//         data->a.numbers[i] = data->a.numbers[i - 1];
//         i--;
//     }
//     data->a.numbers[0] = last;
//     ft_putstr_fd("rra\n", 1);
// }

