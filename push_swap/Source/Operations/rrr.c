/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:36:43 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/28 15:36:47 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	rrr(t_push_swap *data);

void	rrr(t_push_swap *data)
{
	rra(data, 0);
	rrb(data, 0);
	ft_putstr_fd("rrr\n", 1);
}
