/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:32:36 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/24 23:17:23 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void    pa(t_push_swap *data);


void    pa(t_push_swap *data)
{
    if (data->b.top == -1)
        return ;
    printf("this is a.value :%d\n", data->a.numbers[data->a.top]);
    printf("this is b.value : %d\n", data->b.numbers[data->b.top]);
    data->a.top++;
    data->a.numbers[data->a.top] = data->b.numbers[data->b.top];
    data->b.top--;
    data->b.size--;
    
    ft_putstr_fd("pa\n", 1);
    printf("this is a.top :%d\n", data->a.top);
    printf("this is b.top : %d\n", data->b.top);
}

