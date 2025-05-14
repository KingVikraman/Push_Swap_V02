/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:13:58 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/14 16:44:36 by rvikrama         ###   ########.fr       */
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
	struct s_stack *pile;
} t_push_swap;

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
void	rb(t_push_swap *data);
void	ra(t_push_swap *data);
void	rra(t_push_swap *data);
void    rrb(t_push_swap *data);
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
int		ft_atoi(const char *str, int  *error);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);


int		is_sorted(t_stack *a);
int		stack_size(t_stack a);
void	sort_two(t_push_swap *data);
void	sort_five(t_push_swap *data);
void	sort_three(t_push_swap *data);
int		find_lowest_index(t_push_swap *data);
void 	move_to_top_a(t_push_swap *data, int index);
void	use_hardcoded_sort(t_push_swap *data, int count);


void swap(int *a, int *b);
void index_stack(t_stack *a);
void radix_sort(t_push_swap *data);
void smart_merge(t_push_swap *data);
int find_max_position(t_stack stack);
void msb_pass(t_push_swap *data, int bit);
void lsb_pass(t_push_swap *data, int bit);
int find_position(t_stack stack, int num);
void rotate_to_top_b(t_push_swap *data, int num);




#endif