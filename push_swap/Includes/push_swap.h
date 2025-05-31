/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:13:58 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/25 23:17:43 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <math.h>



typedef struct s_stack{
	int *numbers;
	int count;
	int size;
	int top; // number[0]
} t_stack;

typedef struct s_push_swap{
	t_stack a;
	t_stack b;
	int error;
	long result;
	int	sign;
	struct s_stack *pile;
} t_push_swap;

typedef struct s_move {
    int cost;
    int rot_a;
    int rot_b;
} t_move;

// ~~~~ Parsing Funtion ~~~~~
t_push_swap	*parse_check(int argc, char **argv);

// ~~~~ Swap Operations ~~~~
void    sa(t_push_swap *data);
void    sb(t_push_swap *data);
void 	ss(t_push_swap *data);

// ~~~~ Push Operations ~~~~
void 	pa(t_push_swap *data);
void 	pb(t_push_swap *data);

// ~~~~ Rotate Operations ~~~~
void	rb(t_push_swap *data, int print);
void	ra(t_push_swap *data, int print);
void    rra(t_push_swap *data, int print);
void    rrb(t_push_swap *data, int print);
void	rrr(t_push_swap *data);
void    rr(t_push_swap *data);


// ~~~~ Print Functions ~~~~~
// void 	print_stack(t_stack *stack,char name);
void    print_stack_a(t_stack *pile, char name);
void    print_stack_b(t_stack *pile, char name);

// ~~~~ Utils Function ~~~~
size_t	ft_strlen(const char *str);
void	ft_free_split(char **split);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
int	ft_atoi(const char *str, int *error);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

// ~~~~~~ Initialising Functions  ~~~~~~~

int		count_elements(char **split);
int		init_stack_b(t_stack *b, int count);
t_push_swap	*init_data_structure(void);
int	init_stack_a(t_stack *a, char **split, int count);
int		initialize_stacks(t_push_swap *data, char **split, int count);


void	free_all(t_push_swap *data);
int		is_sorted(t_stack *a);
int		stack_size(t_stack a);
void	sort_two(t_push_swap *data);
void	sort_five(t_push_swap *data);
void	sort_three(t_push_swap *data);
int		find_lowest_index(t_push_swap *data);
void 	move_to_top_a(t_push_swap *data, int index);
void	use_hardcoded_sort(t_push_swap *data, int count);
int	has_duplicate(int *numbers, int size);
void    update_cheapest(t_push_swap *data, t_move *cheapest, int i);



int ft_abs(int num);
void swap(int *a, int *b);
void index_stack(t_stack *a);
int get_max_bits(t_stack *stack);
void sort_large(t_push_swap *data);
int find_min_position(t_stack *a);
void bubble_sort(int *arr, int size);
void move_to_top(t_push_swap *data, int min_pos);
int get_rotation_count(t_stack *s, int pos);
int find_target_position(t_push_swap *data, int num);
t_move find_cheapest_move(t_push_swap *data);
void execute_cheapest_move(t_push_swap *data, t_move move);
int calculate_cost(int a_rot, int b_rot);

void	exec_double_rotate(t_push_swap *data, t_move *move);
void	exec_single_rotate_a(t_push_swap *data, t_move *move);
void	exec_single_rotate_b(t_push_swap *data, t_move *move);



#endif