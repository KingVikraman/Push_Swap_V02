/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:48:27 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/05 18:43:41 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"


void sb(t_push_swap *data);
void    print_stack_b(t_push_swap *data, char name);

void    sb(t_push_swap *data)
{
    int temp;

    if(data->b.top < 1)
        return ;
    temp = data->b.numbers[data->b.top];
    data->b.numbers[data->b.top] = data->b.numbers[data->b.top - 1];
    data->b.numbers [data->b.top -1] = temp;
    ft_putstr_fd("sb\n", 1);
}

void    print_stack_b(t_push_swap *data, char name)
{
    int i;

    ft_putstr_fd("Stack ", 1);
    ft_putchar_fd(name, 1);
    ft_putstr_fd(": ", 1);

    if (data->pile->top == -1)
    {
        ft_putstr_fd("(empty)\n", 1);
        return ;
    }

    i = data->pile->top;
    while (i  >= 0)
    {
        ft_putnbr_fd(data->pile->numbers[i], 1);
        ft_putchar_fd(' ', 1);
        i--;
    }
    ft_putchar_fd('\n', 1);
}

// void print_stack_b(t_push_swap *data)
// {
//     printf("Stack B:\n");

//     if (data->b.top == -1)
//     {
//         printf("[empty]\n");
//         return;
//     }

//     for (int i = data->b.top; i >= 0; i--)
//     {
//         printf("%d\n", data->b.numbers[i]);
//     }
// }
