/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:44:36 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/04 19:48:12 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"


void    rrb(t_push_swap *data);

void    rrb(t_push_swap *data)
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
    ft_putstr_fd("rrb\n", 1);
}