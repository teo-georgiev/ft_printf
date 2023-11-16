/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:32:28 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/16 14:03:22 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	f_print_unsigned_int(unsigned int nbr)
{
	int		len;
	int		flag;
	char	*base;

	len = 0;
	flag = 0;
	base = "0123456789";
	if (nbr / 10 != 0)
	{
		flag = f_print_unsigned_int(nbr / 10);
		if (flag == -1)
			return (-1);
		len += flag;
	}
	flag = ft_putchar_fd(base[nbr % 10], 1);
	if (flag == -1)
		return (-1);
	return (len += flag);
}
