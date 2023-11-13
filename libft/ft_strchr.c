/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:06:42 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/06 08:05:19 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	while (c >= 256)
		c -= 256;
	len = ft_strlen(s);
	while (i++ <= len)
	{
		if (*s == c)
		{
			ptr = (char *)s;
			return (ptr);
		}
		s++;
	}
	return (0);
}
