/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:28:15 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/08 12:34:06 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return;
	
	i = 0;
	while (split[i])
	{
		free(split[i]);  // Free each string
		i++;
	}
	free(split);  // Free the array
}
