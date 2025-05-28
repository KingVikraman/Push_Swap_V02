/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:02:24 by rvikrama          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/27 22:49:15 by rvikrama         ###   ########.fr       */
=======
/*   Updated: 2025/05/27 22:21:03 by rvikrama         ###   ########.fr       */
>>>>>>> f8ab9151cc5c418252020c314a64c349436db3df
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void	rra(t_push_swap *data, int print);

void	rra(t_push_swap *data, int print)
{
	int	i;
	int	temp;

	if (data->a.top < 1)
		return ;
	temp = data->a.numbers[0];
	i = 0;
	while (i < data->a.top)
	{
		data->a.numbers[i] = data->a.numbers[i + 1];
		i++;
	}
	data->a.numbers[data->a.top] = temp;
	if (print)
		ft_putstr_fd("rra\n", 1);
}
