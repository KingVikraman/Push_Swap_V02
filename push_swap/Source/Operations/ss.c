/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:38:21 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 15:38:25 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	ss(t_push_swap *data);

// this function is called the ss which is technically the sa and
// sb done at the same time.
void	ss(t_push_swap *data)
{
	sa(data);
	sb(data);
	ft_putstr_fd("ss\n", 1);
}
