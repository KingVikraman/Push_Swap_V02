/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:52:07 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 13:44:47 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../Includes/push_swap.h"


static void	cleanup_parse(t_push_swap *data, char **split);
t_push_swap *parse_check(int argc, char **argv);
static void *combine_args(int argc, char **argv);
int		main(int argc, char **argv);


int		main(int argc, char **argv)
{
	t_push_swap *data;// <- custom struct made by me, in the header file.
	int count;

	if (argc < 2){								//  |_ This is the fucntion that help check
		ft_putstr_fd("Error\n", 1);		 //  |  if the arguments that are parsed in are valid
		return (1);								// -|  or just the output file.
	}
	
	data = parse_check(argc, argv); // <- this function calls parse_check and pushes the ac and av data, then assigns that to the struct.
	if (!data || data->error){						//  -|												//	 |
		ft_putstr_fd("Error\n", 2);			 //	  |
		if (data)									//   |____This fucntion is the function that checks weather in the data
			free(data->a.numbers);				//    | 	assigning part got any errors or not then prints out the
		free(data->b.numbers);					//    |		error in the terminal, free the data to prevent memory leaks
		free(data);							//    |		and exits by returning (1).
		return (1);									//  -|
	}
	count = data->a.size;
	data->b.numbers = malloc(sizeof(int) * data->a.size);
	data->b.size = 0;
	data->b.top = -1;
	if (is_sorted(&data->a)){
		free(data->a.numbers);	
		free(data);
		return (0);
	}
	if (has_duplicate(data->a.numbers, data->a.size))
	{
		ft_putstr_fd("Error\n", 1);
		free(data->a.numbers);
		free(data->b.numbers);
		free(data);
		return (1);
	}
	if (count <= 5)
		use_hardcoded_sort(data, count);
	else
	    index_stack(&data->a);
		sort_large(data);
	free(data->a.numbers);
	free(data->b.numbers);
	free(data);
	return (0);
}


static void *combine_args(int argc, char **argv)
{
	char	*combined;
	size_t	total_len;
	int				i;

	total_len = 0;
	i = argc;
	while(--i >= 1)
	{
		total_len += ft_strlen(argv[i]) + 1;
	}
	combined = ft_calloc(total_len + 1, sizeof(char));
	if (!combined)
		return (NULL);

	i = 1;
	while (i < argc)
	{
		ft_strlcat(combined, argv[i],total_len + 1);
		if (i < argc - 1)
			ft_strlcat(combined, " ", total_len + 1);
		i++;
	}
	return (combined);
}

t_push_swap	*parse_check(int argc, char **argv)
{
	char		*combined;
	char		**split;
	t_push_swap	*data;
	int			count;

	if (argc < 2)
		return (NULL);
	combined = combine_args(argc, argv);
	if (!combined)
		return (NULL);
	split = ft_split(combined, ' ');
	free(combined);
	if (!split)
		return (NULL);
	count = count_elements(split);
	data = init_data_structure();
	if (!data || !initialize_stacks(data, split, count))
	{
		cleanup_parse(data, split);
		return (NULL);
	}
	ft_free_split(split);
	return (data);
}

static void	cleanup_parse(t_push_swap *data, char **split)
{
	ft_free_split(split);
	if (data)
	{
		if (data->a.numbers)
			free(data->a.numbers);
		if (data->b.numbers)
			free(data->b.numbers);
		free(data);
	}
}
