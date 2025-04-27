/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:52:07 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/27 17:59:35 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Includes/push_swap.h"

// int		main(int argc, char **argv)
// {
// 	t_stack *a;
// 	t_stack *b

// 	a = NULL;
// 	b = NULL;
// 	if ( argc == 1)
// }


 Number testing, seeing weather the numbers can be processed nicely or not?



typedef struct s_push_swap{
	int *numbers;
	int count;
	int error;
} t_push_swap;


int		main(int argc, char **argv)
{
	t_puah_swap *data;
	int i;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	data = parse_basic(argv, argc);
	if (!data || data->error)
	{
		ft_putstr_fd("Error\n", 2);
        if (data)
            free(data->numbers);
        free(data);
        return (1);
	}
	
	i = 0;
    while (i < data->count)
    {
        ft_putnbr_fd(data->numbers[i], 1);
        ft_putchar_fd(' ', 1);
        i++;
    }
    ft_putchar_fd('\n', 1);

    free(data->numbers);
    free(data);
    return (0);

}


static void init_parser(t_push_swap *data, int count)
{
	data->count = count;
	data->error = 0;
	data->numbers = malloc(sizeof(int) * count);
}
t_push_swap		parse_check(int argc, char **argv)
{
	t_push_swap *data;
    int i;

    data = malloc(sizeof(t_push_swap));
    if (!data)
        return (NULL);

	init_parser_data(data, argc - 1);
	if (!data->numbers)
    {
        free(data);
        return (NULL);
    }

	i = 1;
	while(i < argc)
	{
		data->numbers[i - 1] = ft_atoi(argv[i]);
        i++;
	}

	return (data);

}



