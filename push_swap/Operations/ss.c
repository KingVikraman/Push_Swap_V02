/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:37:17 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/06 15:42:06 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../Includes/push_swap.h"

void    ss(t_push_swap *data);

//this function is called the ss which is technically the sa and 
//sb done at the same time.
void    ss(t_push_swap *data)
{
    sa(data);
    sb(data);
    ft_putstr_fd("ss\n", 1);
}