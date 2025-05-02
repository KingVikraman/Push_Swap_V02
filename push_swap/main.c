/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:52:07 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/02 13:33:45 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Includes/push_swap.h"



t_push_swap *parse_check(int argc, char **argv);
static void *combine_args(int argc, char **argv);
int		main(int argc, char **argv);


int		main(int argc, char **argv) //<- Parses in a argument count and vector.
{
	t_push_swap *data;// <- custom struct made by me, in the header file.
	if (argc < 2)								// -|
	{											//  |_ This is the fucntion that help check 
		ft_putstr_fd("Error\n", 1);		 //  |  if the arguments that are parsed in are valid
		return (1);								// -|  or just the output file.
	}

	data = parse_check(argc, argv); // <- this function calls parse_check and pushes the ac and av data, then assigns that to the struct.
	if (!data || data->error)						//  -|
	{												//	 |
		ft_putstr_fd("Error2\n", 2);			 //	  |	
		if (data)									//   |____This fucntion is the function that checks weather in the data
			free(data->a.numbers);				//    | 	assigning part got any errors or not then prints out the 
		free(data->b.numbers);					//    |		error in the terminal, free the data to prevent memory leaks
		free(data);							//    |		and exits by returning (1).
		return (1);									//  -|
	}
	
	data->b.numbers = malloc(sizeof(int) * data->a.size);
	data->b.size = data->a.size;
	data->b.top = -1;
	// data->a.numbers = malloc(sizeof(int) * data->b.size);
	// data->a.size = data->b.size;
	// data->a.top = -1;

	print_stack(&data->a, 'a');

	sa(data);
	ft_putstr_fd("After sa:\n", 1);
	print_stack(&data->a, 'a');
	// i = 0;
	// while (i < data->count)
	// {
	//     ft_putnbr_fd(data->a.numbers[i], 1);
	//     ft_putchar_fd(' ', 1);
	//     i++;
	// }
	// ft_putchar_fd('\n', 1);
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
		total_len += ft_strlen(argv[i]) + 1;
	
	combined = ft_calloc(total_len + 1, sizeof(char));
	if (!combined)
		return (NULL);

	i = argc ;
	while (--i >= 1)
	{
		ft_strlcat(combined, argv[i],total_len + 1);
		if (i != 1)
			ft_strlcat(combined, " ", total_len + 1);
	}
	return (combined);
}


t_push_swap *parse_check(int argc, char **argv)
{
	char        *combined;
	char        **split;
	int         i;
	t_push_swap *data;

	if (argc < 2)
		return (NULL);

	// Combine arguments into single string
	combined = combine_args(argc, argv);
	if (!combined)
		return (NULL);

	// Split into individual number strings
	split = ft_split(combined, ' ');
	free(combined);
	if (!split)
		return (NULL);

	// Count the numbers
	int count = 0;
	while (split[count])
		count++;

	// Allocate main structure
	data = malloc(sizeof(t_push_swap));
	if (!data)
		return (ft_free_split(split), NULL);

	// Initialize stack A
	data->a.numbers = malloc(sizeof(int) * count);
	if (!data->a.numbers)
		return (ft_free_split(split), free(data), NULL);

	// Initialize stack B (will be empty at start)
	data->b.numbers = malloc(sizeof(int) * count);
	if (!data->b.numbers)
	{
		free(data->a.numbers);
		free(data);
		return (ft_free_split(split), NULL);
	}

	// Parse numbers into stack A
	data->error = 0;
	i = -1;
	while (count > ++i)
	{
		data->a.numbers[i] = ft_atoi(split[i], &data->error);
		if (data->error)
			break;
	}

	// Set stack metadata
	data->a.size = count;
	data->a.top = count - 1;  // Top points to last element
	data->b.size = count;
	data->b.top = -1;         // Stack B starts empty

	ft_free_split(split);
	return (data);
}

// static void init_parser(t_push_swap *data, int count)
// {
// 	data->count = count;
// 	data->error = 0;
// 	data->numbers = malloc(sizeof(int) * count);
//     if (!data->numbers)
//     data->error = 1;
// }

// t_push_swap	*parse_check(int argc, char **argv)
// {
// 	t_push_swap	*data;
// 	char		*combined;
// 	char		**split;
// 	int			i;

// 	if (argc < 2)
// 		return (NULL);

// 	combined = combine_args(argc, argv);
// 	if (!combined)
// 		return (NULL);

// 	split = ft_split(combined, ' ');
// 	free(combined);
// 	if (!split)
// 		return (NULL);

// 	data = malloc(sizeof(t_stack));
// 	if (!data)
// 		return (ft_free_split(split), NULL);

// 	data->count = 0;
// 	while (split[data->count])
// 		data->count++;

// 	data->numbers = malloc(sizeof(int) * data->count);
// 	if (!data->numbers)
// 		return (ft_free_split(split), free(data), NULL);

// 	i = -1;
// 	data->error = 0;
// 	while (++i < data->count)
// 	{
// 		data->numbers[i] = ft_atoi(split[i], &data->error);
// 		if (data->error)
// 			break ;
// 	}

// 	ft_free_split(split);
// 	return (data);
// }




