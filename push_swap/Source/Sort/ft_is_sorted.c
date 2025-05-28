/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:38:37 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/27 22:21:53 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

int	is_sorted(t_stack *a);

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->size <= 1)
		return (1); // empty or single element = sorted
	i = a->top;
	while (i > 0)
	{
		if (a->numbers[i] > a->numbers[i - 1])
			return (0); // Not sorted
		i--;
	}
	ft_putstr_fd("Numbers are sorted ;-).\n", 1);
	return (1); // Sorted
}
