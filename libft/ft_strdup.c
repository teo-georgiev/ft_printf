/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:13:03 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/06 08:05:32 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*s2;

	i = -1;
	len = ft_strlen(s1);
	s2 = malloc(len * sizeof(char) + 1);
	if (!s2)
		return (0);
	while (++i <= len)
		s2[i] = s1[i];
	return (s2);
}
