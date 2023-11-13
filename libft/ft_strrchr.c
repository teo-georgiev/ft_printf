/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:06:42 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/06 08:06:25 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	cc;

	while (c > 256)
		c -= 256;
	cc = (char)c;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == cc)
			return ((char *)&s[len]);
		len--;
	}
	if (s[len] == c)
		return ((char *)&s[len]);
	return (0);
}
