/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:01:42 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/16 14:06:15 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	flag;
	int	len;

	flag = 0;
	len = 0;
	if (s == 0)
		return (-1);
	while (s[len])
	{
		flag = ft_putchar_fd(s[len], fd);
		if (flag != 1)
			return (-1);
		len += flag;
	}
	return (len);
}
