/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:13:58 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/02 14:26:38 by rvikrama         ###   ########.fr       */
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
	int top;
} t_stack;

typedef struct s_push_swap{
	t_stack a;
	t_stack b;
	int error;
	struct s_stack *data;
} t_push_swap;

// ~~~~ Parsing Funtion ~~~~~
t_push_swap	*parse_check(int argc, char **argv);

// ~~~~ Swap Operations ~~~~
void    sa(t_push_swap *data);
void    sb(t_push_swap *data);
void print_stack_b(t_push_swap *data);
void 	ss(t_push_swap *data);

// ~~~~ Push Operations ~~~~
void pa(t_push_swap *data);
void pb(t_push_swap *data);

// ~~~~ Print Functions ~~~~~
void 	print_stack(t_stack *stack,char name);


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


#endif