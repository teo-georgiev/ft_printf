/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:18:11 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/15 18:07:46 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		flag;

	num = n;
	flag = 0;
	if (num < 0)
	{
		flag += ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num > 9)
	{
		flag += ft_putnbr_fd(num / 10, fd);
		flag += ft_putchar_fd(num % 10 + '0', fd);
	}
	if (num <= 9)
		flag += ft_putchar_fd(num % 10 + '0', fd);
	return (flag);
}
