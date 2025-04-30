/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:24:11 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/29 16:25:09 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../Includes/push_swap.h"


void	*ft_calloc(size_t nitems, size_t size)
{
	char			*a;
	unsigned int	tot;
	size_t			i;

	tot = size * nitems;
	a = malloc(size * nitems);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (tot > 0)
	{
		a[i] = 0;
		i++;
		tot--;
	}
	return ((void *)a);
}