/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:52:07 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/29 17:25:24 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Includes/push_swap.h"


t_push_swap	*parse_check(int argc, char **argv);
int		main(int argc, char **argv);

int		main(int argc, char **argv)
{
	t_push_swap *data;
	int i;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	data = parse_check(argc, argv);
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


// static void init_parser(t_push_swap *data, int count)
// {
// 	data->count = count;
// 	data->error = 0;
// 	data->numbers = malloc(sizeof(int) * count);
//     if (!data->numbers)
//     data->error = 1;
// }
static void *combine_args(int argc, char **argv)
{
    char	*combined;
	size_t	total_len;
	int				i;

	total_len = 0;
	i = 0;
	while(++i < argc)
		total_len += ft_strlen(argv[i]) + 1;
	
	combined = ft_calloc(total_len + 1, sizeof(char));
	if (!combined)
		return (NULL);

	i = 0;
	while (++i < argc)
	{
		ft_strlcat(combined, argv[i],total_len + 1);
		if (i != argc -1)
			ft_strlcat(combined, " ", total_len + 1);
	}
	return (combined);
}

t_push_swap	*parse_check(int argc, char **argv)
{
	t_push_swap	*data;
	char		*combined;
	char		**split;
	int			i;

	if (argc < 2)
		return (NULL);

	combined = combine_args(argc, argv);
	if (!combined)
		return (NULL);

	split = ft_split(combined, ' ');
	free(combined);
	if (!split)
		return (NULL);

	data = malloc(sizeof(t_push_swap));
	if (!data)
		return (ft_free_split(split), NULL);

	data->count = 0;
	while (split[data->count])
		data->count++;

	data->numbers = malloc(sizeof(int) * data->count);
	if (!data->numbers)
		return (ft_free_split(split), free(data), NULL);

	i = -1;
	data->error = 0;
	while (++i < data->count)
	{
		data->numbers[i] = ft_atoi(split[i], &data->error);
		if (data->error)
			break ;
	}

	ft_free_split(split);
	return (data);
}


