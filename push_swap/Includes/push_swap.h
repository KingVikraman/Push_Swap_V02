/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:13:58 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/27 17:59:31 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct s_push_swap{
	int *numbers;
	int count;
	int error;
} t_push_swap;

t_stack a;
t_stack b;
#endif