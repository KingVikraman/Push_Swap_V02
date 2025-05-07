/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:49:05 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/06 15:42:21 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../Includes/push_swap.h"

void    rrr(t_push_swap *data);

void    rrr(t_push_swap *data)
{
    rra(data);
    rrb(data);
    ft_putstr_fd("rrr\n", 1);
}
