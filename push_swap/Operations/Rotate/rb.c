/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:42:40 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/03 22:43:44 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"


void	rb(t_push_swap *data);

void	rb(t_push_swap *data)
{
	int i;
	int temp;

	if (data->b.top < 1)
		return ;

	temp = data->b.numbers[data->b.top];

	i = data->b.top;
	while (i > 0)
	{
		data->b.numbers[i] = data->b.numbers[i - 1];
		i--;
	}
	data->b.numbers[0] = temp;
	ft_putstr_fd("rb\n", 1);
}