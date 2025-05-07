/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:48:18 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/07 23:35:46 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include    "../Includes/push_swap.h"


void    sa(t_push_swap *data);
void    print_stack_a(t_stack *pile, char name);

void    sa(t_push_swap *data)
{
    int temp;

    if(data->a.top < 1)
        return ;
    temp = data->a.numbers[data->a.top];
    //printf("%d\n", temp);
    data->a.numbers[data->a.top] = data->a.numbers[data->a.top - 1];
    data->a.numbers [data->a.top -1] = temp;
    ft_putstr_fd("sa\n", 1);
}


// This function help in printing the numbers and output onto the 
// terminal.

void    print_stack_a(t_stack *pile, char name)
{
    int i;

    ft_putstr_fd("Stack ", 1);
    ft_putchar_fd(name , 1);
    ft_putstr_fd(": ", 1);

    if (pile->top == -1)
    {
        ft_putstr_fd("(empty)\n", 1);
        return ;
    }

    i = 0;
    while (i <= pile->top)
    {
        ft_putnbr_fd(pile->numbers[i], 1);
        ft_putchar_fd(' ', 1);
        i++;
    }
    ft_putchar_fd('\n', 1);
}

// void print_stack_a(t_push_swap *data)
// {
//     printf("Stack A:\n");

//     if (data->a.top == -1)
//     {
//         printf("[empty]\n");
//         return;
//     }

//     for (int i = data->a.top; i >= 0; i--)
//     {
//         printf("%d\n", data->a.numbers[i]);
//     }
// }
