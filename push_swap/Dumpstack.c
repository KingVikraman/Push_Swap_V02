// pb(data);
	// ft_putstr_fd("After pa:\n", 1);
	// print_stack_b(data);
	// print_stack(&data->a, 'a');
	// pa(data);
	// pa(data);
	// print_stack(&data->a, 'a');
	// print_stack_b(data);

	// i = 0;
	// while (i < data->count)
	// {
	//     ft_putnbr_fd(data->a.numbers[i], 1);
	//     ft_putchar_fd(' ', 1);
	//     i++;
	// }
	// ft_putchar_fd('\n', 1);


    // pb(data);
	// //ft_putstr_fd("After pb:\n", 1);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');

	// pb(data);
	// //ft_putstr_fd("After pb:\n", 1);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b,'b');

	// sb(data);
	// ft_putstr_fd("After sb:\n", 1);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b,'b');


	// data->a.numbers = malloc(sizeof(int) * data->b.size);
	// data->a.size = data->b.size;
	// data->a.top = -1;

	// print_stack(&data->a, 'a');
	// print_stack(&data->b, 'b');
	// ft_putstr_fd("before pb:\n", 1);

	// pb(data);

	// print_stack(&data->a, 'a');
	// print_stack(&data->b, 'b');
	// ft_putstr_fd("After pb:\n", 1);


	// pa(data);

	// print_stack(&data->a, 'a');
	// print_stack(&data->b, 'b');
	// ft_putstr_fd("After pa:\n", 1);


	//sa(data);
	//ft_putstr_fd("After sa:\n", 1);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');

	// while(data->a.top >= 4 )
	// {
	// 	pb(data);
	// 	print_stack_a(&data->a, 'a');
	// 	print_stack_b(&data->b, 'b');
	// }

	// ra(data);
	// rb(data);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');

	// rra(data);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');

	// ss(data);
	// //ft_putstr_fd("After sa:\n", 1);
	// print_stack_a(&data->a, 'a');
	// print_stack_b(&data->b, 'b');

	// while (data->b.top >= 0 )
	// {
	// 	pa(data);
	// 	//pa(data);
	// 	//ft_putstr_fd("After pa:\n", 1);
	// 	print_stack_a(&data->a, 'a');
	// 	print_stack_b(&data->b,'b');
	// }


	// data->error = 0;
	// i = 0;
	// while (i < count)
	// {
	// 	// data->a.numbers[i] = ft_atoi(split[i], &data->error);
	// 	data->a.numbers[count - 1 - i] = ft_atoi(split[i], &data->error);
	// 	if (data->error)
	// 		break;
	// 	i++;
	// }

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


