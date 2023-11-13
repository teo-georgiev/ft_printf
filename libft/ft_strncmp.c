/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:40:15 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/06 08:06:12 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cmp_s1;
	unsigned char	*cmp_s2;

	i = 0;
	cmp_s1 = (unsigned char *)s1;
	cmp_s2 = (unsigned char *)s2;
	while ((cmp_s1[i] || cmp_s2[i]) && i < n)
	{
		if (cmp_s1[i] > cmp_s2[i])
			return (1);
		if (cmp_s1[i] < cmp_s2[i])
			return (-1);
		i++;
	}
	return (0);
}
