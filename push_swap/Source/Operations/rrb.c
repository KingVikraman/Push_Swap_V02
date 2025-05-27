/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:44:36 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/25 23:08:13 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"


void    rrb(t_push_swap *data, int print);

void    rrb(t_push_swap *data, int print)
{
    int i;
    int temp;

    if (data->b.top < 1)
        return ;

    temp = data->b.numbers[0];

    i = 0;
    while (i < data->b.top)
    {
        data->b.numbers[i] = data->b.numbers[i + 1];
        i++;
    }
    data->b.numbers[data->b.top] = temp;

    if(print)
        ft_putstr_fd("rrb\n", 1);
}

// void rrb(t_push_swap *data)
// {
//     int last = data->b.numbers[data->b.size - 1];
//     int i = data->b.size -1;
//     while (i > 0) {
//         data->b.numbers[i] = data->b.numbers[i - 1];
//         i--;
//     }
//     data->b.numbers[0] = last;
//     ft_putstr_fd("rrb\n", 1);
//}