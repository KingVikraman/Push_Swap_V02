/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:26:41 by rvikrama          #+#    #+#             */
/*   Updated: 2025/05/08 12:34:10 by rvikrama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#include "../../Includes/push_swap.h"


static int	word_count(const char *s, char c)
{
	int count = 0;
	int in_word = 0;

	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int end)
{
	char *word = malloc(end - start + 1);
	int i = 0;

	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i = 0, j = 0, start = -1;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || (s[i + 1] == '\0' && s[i] != c)) && start != -1)
		{
			if (s[i] == c)
				res[j++] = word_dup(s, start, i);
			else
				res[j++] = word_dup(s, start, i + 1);
			start = -1;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
