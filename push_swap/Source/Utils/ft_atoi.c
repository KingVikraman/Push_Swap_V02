/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:03:43 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/27 22:25:23 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../Includes/push_swap.h"

int		ft_atoi(const char *str, int  *error)
{
	int					sign;
	long 				result;
	const char 			*start = str;

	result = 0;
	sign = 1;
	*error = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;

	
	if (*str == '+' || *str == '-') 
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)||
			(sign == -1 && result > (long)INT_MAX + 1))
			{
				*error = 1;
				return (0);
			}
		str++;
	}
	if (*str != '\0' || str == start || (*(str -1) == '+' || *(str - 1)
	== '-'))
		*error = 1;
		 
	return ((int)(result * sign));
}
/*

int    ft_atoi_safe(const char *str, int *error)
5	{
6	    long    result;
7	    int        sign;
8	    const char *start = str;
9	
10	
11	    result = 0;
12	    sign = 1;
13	    *error = 0;
14	
15	    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
16	        str++;
17	
18	    if (*str == '-')
19	        sign = -1;
20	    if (*str == '-' || *str == '+')
21	        str++;
22	
23	    while (*str >= '0' && *str <= '9')
24	    {
25	        result = result * 10 + (*str - '0');
26	        if ((sign == 1 && result > INT_MAX) || 
27	            (sign == -1 && -result < INT_MIN))
28	        {
29	            *error = 1;
30	            return (0);
31	        }
32	        str++;
33	    }
34	
35	    if (*str != '\0' || str == start) // Check for invalid chars
36	        *error = 1;
37	
38	    return (result * sign);
39	}
40	
41	int main(void)
42	{
43	    const char *inputs[] = {
44	        "123",
45	        "-456",
46	        "abc",
47	        "2147483648",  // Overflow test
48	        "-2147483649", // Underflow test
49	        "   +42",
50	        "0042",
51	        NULL // very important to mark end of array
52	    };
53	    int i = 0;
54	    int error, result;
55	
56	    while (inputs[i] != NULL)
57	    {
58	        result = ft_atoi_safe(inputs[i], &error);
59	        if (error)
60	            printf("Input \"%s\" is INVALID \n", inputs[i]);
61	        else
62	            printf("Input \"%s\" is VALID -> Result: %d\n", inputs[i], result);
63	        i++;
64	    }
65	
66	    return 0;
67	}
Edit this code
 line that just executed


*/