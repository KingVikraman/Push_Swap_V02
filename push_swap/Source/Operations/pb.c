/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:48:36 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/24 23:46:27 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"
void    pb(t_push_swap *data);


void    pb(t_push_swap *data)
{
	if (data->a.top == -1)
		return ;

	data->b.top++;                     
	data->b.numbers[data->b.top] = data->a.numbers[data->a.top];
	data->a.top--;

	ft_putstr_fd("pb\n", 1);
}



