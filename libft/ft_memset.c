/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:01:37 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/06 08:01:23 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	symbol;
	size_t			i;

	ptr = (unsigned char *)b;
	symbol = (unsigned char)c;
	i = 0;
	while (i < len)
		ptr[i++] = symbol;
	return (b);
}
