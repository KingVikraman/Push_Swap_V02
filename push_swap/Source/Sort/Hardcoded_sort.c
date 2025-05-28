/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hardcoded_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:10:47 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/27 22:22:11 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

int		is_sorted(t_stack *a);
void	use_hardcoded_sort(t_push_swap *data, int count);

void	use_hardcoded_sort(t_push_swap *data, int count)
{
	if (count <= 1)
		return ;
	else if (count == 2)
		sort_two(data);
	else if (count == 3)
		sort_three(data);
	else if (count == 4)
		sort_five(data);
	else if (count == 5)
		sort_five(data);
}

int		is_sorted(t_stack *a)
{
	int	i;

	if (a->size <= 1)
		return (1);
	i = a->top;
	while (i > 0)
	{
		if (a->numbers[i] > a->numbers[i - 1])
			return (0);
		i--;
	}
	ft_putstr_fd("Error\n", 1);
	return (1);
}