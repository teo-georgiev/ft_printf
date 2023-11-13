/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:31 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/06 08:06:32 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	char	*s_trim;

	i = 0;
	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	s_len = ft_strlen(s1);
	while (i < s_len && ft_strchr(set, s1[i]))
		i++;
	while (i < s_len && ft_strchr(set, s1[s_len - 1]))
		s_len--;
	s_trim = (char *)malloc((s_len - i + 1) * sizeof(char));
	if (!s_trim)
		return (0);
	j = -1;
	while (++j < s_len - i)
		s_trim[j] = s1[i + j];
	s_trim[s_len - i] = '\0';
	return (s_trim);
}
