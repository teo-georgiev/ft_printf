/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:18:11 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/16 14:18:12 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		len;
	int		flag;

	nbr = n;
	len = 0;
	flag = 0;
	if (nbr < 0)
	{
		len = ft_putchar_fd('-', fd);
		if (len == -1)
			return (-1);
		nbr *= -1;
	}
	if (nbr / 10 != 0)
	{
		flag = ft_putnbr_fd(nbr / 10, fd);
		if (flag == -1)
			return (-1);
		len += flag;
	}
	flag = ft_putchar_fd(nbr % 10 + '0', fd);
	if (flag == -1)
		return (-1);
	return (len += flag);
}
