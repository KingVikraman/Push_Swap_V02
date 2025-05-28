/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:04:45 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 16:04:46 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../Includes/push_swap.h"

int		count_elements(char **split);
int		init_stack_b(t_stack *b, int count);
t_push_swap	*init_data_structure(void);
int		init_stack_a(t_stack *a, char **split, int count);
int		initialize_stacks(t_push_swap *data, char **split, int count);

int	init_stack_a(t_stack *a, char **split, int count)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	a->numbers = malloc(sizeof(int) * count);
	if (!a->numbers)
		return (0);
	while (i < count){
		a->numbers[i] = ft_atoi(split[count - i - 1], &error);
		if (error){
			free(a->numbers);
			a->numbers = NULL;
			return (0);
		}
		i++;
	}
	a->size = count;
	a->top = count - 1;
	return (1);
}

int	init_stack_b(t_stack *b, int count)
{
	b->numbers = malloc(sizeof(int) * count);
	if (!b->numbers)
		return (0);
	b->size = 0;
	b->top = -1;
	return (1);
}

int	initialize_stacks(t_push_swap *data, char **split, int count)
{
	if (!init_stack_a(&data->a, split, count) || !init_stack_b(&data->b, count))
		return (0);
	return (1);
}

t_push_swap	*init_data_structure(void)
{
	t_push_swap *data;

	data = malloc(sizeof(t_push_swap));
	if (!data)
		return (NULL);
	data->a.numbers = NULL;
	data->b.numbers = NULL;
	data->error = 0;
	return (data);
}

int	count_elements(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}
