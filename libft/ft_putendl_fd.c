/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:06:35 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/06 08:05:04 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	flag;

	flag = ft_putstr_fd(s, fd);
	if (flag == -1)
		return (-1);
	if (write(fd, "\n", 1) == -1)
		return (-1);
	return (flag + 1);
}
