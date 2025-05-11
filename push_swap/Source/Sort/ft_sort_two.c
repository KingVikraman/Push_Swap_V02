/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:11:04 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/08 12:33:33 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void	sort_two(t_push_swap *data);


void	sort_two(t_push_swap *data)
{
	if(data->a.numbers[data->a.top] > data->a.numbers[data->a.top - 1])
		sa(data);
}
