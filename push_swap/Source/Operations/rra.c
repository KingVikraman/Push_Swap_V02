/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:02:24 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/27 19:07:57 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "../../Includes/push_swap.h"


void	rra(t_push_swap *data, int print);

void	rra(t_push_swap *data, int print)
{
	int i;
	int temp;

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
	
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');
    // printf("_______________________\n");
    // printf("this is a.value :%d\n", data->a.numbers[data->a.top]);
    // printf("this is b.value : %d\n", data->b.numbers[data->b.top]);
    // printf("This is the size of stack A: %d\n", data->a.size);
    // printf("This is the size of stack B: %d\n", data->b.size);
}


// void rra(t_push_swap *data)
// {
//     int last = data->a.numbers[data->a.size - 1];
//     int i = data->a.size - 1;
//     while (i > 0) {
//         data->a.numbers[i] = data->a.numbers[i - 1];
//         i--;
//     }
//     data->a.numbers[0] = last;
//     ft_putstr_fd("rra\n", 1);
// }

