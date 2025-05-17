/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:02:34 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/17 20:07:34 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "../../Includes/push_swap.h"

void	ra(t_push_swap *data);

// void	ra(t_push_swap *data)
// {
// 	int i;
// 	int temp;
 
// 	if (data->a.top < 1)
// 		return ;

// 	temp = data->a.numbers[data->a.top];

// 	i = data->a.top;
// 	while(i > 0)
// 	{
// 		data->a.numbers[i] = data->a.numbers[i - 1];
// 		i--;
// 	}
// 	data->a.numbers[0] = temp;
// 	ft_putstr_fd("ra\n", 1);
// }

void ra(t_push_swap *data)
{
    // Rotate stack a upwards
    int first = data->a.numbers[0];
    int i = 0;
    while (i < data->a.size - 1) {
        data->a.numbers[i] = data->a.numbers[i + 1];
        i++;
    }
    data->a.numbers[data->a.size - 1] = first;
    ft_putstr_fd("ra\n", 1);
}


