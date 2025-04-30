/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:13:58 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/29 16:36:49 by rvikrama         ###   ########.fr       */
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



typedef struct s_push_swap{
	int *numbers;
	int count;
	int error;
} t_push_swap;


t_push_swap	*parse_check(int argc, char **argv);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_free_split(char **split);
char	**ft_split(const char *s, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str, int  *error);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nitems, size_t size);


#endif