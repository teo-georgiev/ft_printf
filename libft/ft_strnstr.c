/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:33:13 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/06 08:06:19 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*ptr;

	i = 0;
	j = 0;
	ptr = haystack;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if ((len - i) < ft_strlen(needle))
			break ;
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
		{
			ptr = &haystack[i];
			j++;
		}
		if (!needle[j])
			return ((char *)ptr);
		i++;
	}
	return ((char *)0);
}
