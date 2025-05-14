/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hardcoded_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:10:47 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/14 16:50:14 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void	use_hardcoded_sort(t_push_swap *data, int count);


void	use_hardcoded_sort(t_push_swap *data, int count)
{
	if(count <= 1)
		return ;
	else if (count == 2)
		sort_two(data );
	else if (count == 3)
		sort_three(data);
	else if (count == 4)
		sort_five(data);
	else if (count == 5)
		sort_five(data);
}