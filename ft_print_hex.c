/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:31:24 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/17 08:36:47 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	f_print_hex(unsigned long nbr, int f(int))
{
	int		len;
	int		flag;
	char	*base;

	len = 0;
	flag = 0;
	base = "0123456789abcdef";
	if (nbr / 16 != 0)
	{
		flag = f_print_hex(nbr / 16, f);
		if (flag == -1)
			return (-1);
		len += flag;
	}
	flag = ft_putchar_fd(f(base[nbr % 16]), 1);
	if (flag == -1)
		return (-1);
	return (len += flag);
}

int	f_print_address(unsigned long addr)
{
	int	flag;

	flag = 0;
	if (ft_putstr_fd("0x", 1) == -1)
		return (-1);
	flag = f_print_hex(addr, ft_tolower);
	if (flag == -1)
		return (-1);
	return (2 + flag);
}
