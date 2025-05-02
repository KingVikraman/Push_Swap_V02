/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:48:27 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/02 13:31:56 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"


void sb(t_push_swap *data);

void    sb(t_push_swap *data)
{
    int temp;

    if(data->b.top < 1)
        return ;
    temp = data->b.numbers[data->b.top];
    data->b.numbers[data->b.top] = data->b.numbers[data->b.top - 1];
    data->b.numbers [data->b.top -1] = temp;
    ft_putstr_fd("sb\n", 1);
}