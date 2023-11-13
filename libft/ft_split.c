/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:42:09 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/08 10:39:12 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*arr_dup(char const *s, char c)
{
	size_t	j;
	char	*new_s;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	new_s = malloc((j + 1) * sizeof(char));
	if (!new_s)
		return (0);
	if (ft_strlen(s) != ft_strlcpy(new_s, s, j + 1))
		return (0);
	return (new_s);
}

static size_t	word_count_f(char const *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	if (c == '\0')
		return (word_count = 1);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word_count++;
		i++;
	}
	return (word_count);
}

static int	arr_free(char **arr, size_t j)
{
	while (j > 0)
	{
		j--;
		free(arr[j]);
		arr[j] = (void *)0;
	}
	free(arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**arr;

	i = 0;
	j = 0;
	arr = malloc((word_count_f(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	while (s[i] && j < word_count_f(s, c))
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			arr[j] = arr_dup(s + i, c);
			if (!arr[j])
			{
				arr_free(arr, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	arr[j] = (void *)0;
	return (arr);
}
