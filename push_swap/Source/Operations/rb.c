/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:42:40 by rvikrama          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/27 22:49:03 by rvikrama         ###   ########.fr       */
=======
/*   Updated: 2025/05/27 22:21:19 by rvikrama         ###   ########.fr       */
>>>>>>> f8ab9151cc5c418252020c314a64c349436db3df
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void	rb(t_push_swap *data, int print);

void	rb(t_push_swap *data, int print)
{
	int	i;
	int	temp;

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
	if (print)
		ft_putstr_fd("rb\n", 1);
}
