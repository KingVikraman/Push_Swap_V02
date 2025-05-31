/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:24:20 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/29 21:24:21 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

static const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	return (str);
}

static const char	*handle_sign(const char *str, int *sign)
{
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

static const char	*convert_digits(const char *str, long *result, int sign,
	int *error)
{
	while (*str >= '0' && *str <= '9')
	{
		*result = *result * 10 + (*str - '0');
		if ((sign == 1 && *result > INT_MAX)
			|| (sign == -1 && *result > (long)INT_MAX + 1))
		{
			*error = 1;
			return (str);
		}
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str, int *error)
{
	int			sign;
	long		result;
	const char	*start;

	sign = 1;
	result = 0;
	start = str;
	*error = 0;
	str = skip_whitespace(str);
	str = handle_sign(str, &sign);
	str = convert_digits(str, &result, sign, error);
	if (*str != '\0' || str == start
		|| (*(str - 1) == '+' || *(str - 1) == '-'))
		*error = 1;
	return ((int)(result * sign));
}
