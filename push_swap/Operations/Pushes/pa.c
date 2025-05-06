/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:32:36 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/04 19:52:45 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void    pa(t_push_swap *data);


void    pa(t_push_swap *data)
{
    if (data->b.top == -1)
        return ;

    data->a.top++;
    data->a.numbers[data->a.top] = data->b.numbers[data->b.top];
    data->b.top--;

    ft_putstr_fd("pa\n", 1);
}
