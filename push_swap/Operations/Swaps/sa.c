/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:48:18 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/30 17:28:01 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include    "../../Includes/push_swap.h"


void    sa(t_push_swap *data);
void    sb(t_push_swap *data);
void    ss(t_push_swap *data);
void    print_stack(t_stack *stack, char name);

void    sa(t_push_swap *data)
{
    int temp;

    if(data->a.top < 1)
        return ;
    temp = data->a.numbers[data->a.top];
    data->a.numbers[data->a.top] = data->a.numbers[data->a.top - 1];
    data->a.numbers [data->a.top -1] = temp;
    ft_putstr_fd("sa\n", 1);
}

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

void    ss(t_push_swap *data)
{
    sa(data);
    sb(data);
    ft_putstr_fd("ss\n", 1);
}

void    print_stack(t_stack *stack, char name)
{
    int i;

    ft_putstr_fd("Stack ", 1);
    ft_putchar_fd(name, 1);
    ft_putstr_fd(": ", 1);

    if (stack->top == -1)
    {
        ft_putstr_fd("(empty\n)", 1);
        return ;
    }

    i = stack->top;
    while (i  >= 0)
    {
        ft_putnbr_fd(stack->numbers[i], 1);
        ft_putchar_fd(' ', 1);
        i--;
    }
    ft_putchar_fd('\n', 1);
}