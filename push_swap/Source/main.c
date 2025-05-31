/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:47:57 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/29 18:47:59 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	cleanup_parse(t_push_swap *data, char **split);
t_push_swap	*parse_check(int argc, char **argv);
static void	*combine_args(int argc, char **argv);
int			main(int argc, char **argv);
void		free_all(t_push_swap *data);

int	main(int argc, char **argv)
{
	t_push_swap	*data;
	int			count;

	if (argc == 1)
		return 0;
	if (!argv[1] || argv[1][0] == '\0')
		return (ft_putstr_fd("Error\n", 2), 1);
	data = parse_check(argc, argv);
	if (!data || data->error)
		return (ft_putstr_fd("Error\n", 2), free_all(data), 1);
	count = data->a.size;
	data->b.numbers = malloc(sizeof(int) * count);
	data->b.size = 0;
	data->b.top = -1;
	if (has_duplicate(data->a.numbers, data->a.size))
	{
		ft_putstr_fd("Error\n", 2);
		return(free_all(data), 1);
	}
	if (is_sorted(&data->a))
	{
		//printf("Enten Here 4\n");
		return (free_all(data), 0);
	}
	if (count <= 3)
	{
		//printf("Enten Here 5\n");
		use_hardcoded_sort(data, count);
	}
	else
		sort_large(data);
	free_all(data);
	return (0);
}

static void	*combine_args(int argc, char **argv)
{
	char	*combined;
	size_t	total_len;
	int		i;

	total_len = 0;
	i = argc;
	while (--i >= 1)
	{
		total_len += ft_strlen(argv[i]) + 1;
	}
	combined = ft_calloc(total_len + 1, sizeof(char));
	if (!combined)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (argv[i])
		{
			ft_strlcat(combined, argv[i], total_len + 1);
			if (i < argc - 1)
				ft_strlcat(combined, " ", total_len + 1);
		}
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

// put this in a separate .c file or top of main.c
void	free_all(t_push_swap *data)
{
	if (!data)
		return ;
	free(data->a.numbers);
	free(data->b.numbers);
	free(data);
}
