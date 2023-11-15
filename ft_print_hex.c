/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:31:24 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/15 17:43:24 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static size_t	f_convert_to_hex(unsigned long nbr, int f(int))
{
	size_t	len;
	char	*base;
	char	symbol;

	len = 0;
	base = "0123456789abcdef";
	if (nbr / 16 != 0)
		len += f_convert_to_hex(nbr / 16, f);
	symbol = f(base[nbr % 16]);
	len += write(1, &symbol, 1);
	return (len);
}

size_t	f_print_address(unsigned long addr)
{
	size_t	len;

	len = 0;
	ft_putstr_fd("0x", 1);
	len = 2 + f_convert_to_hex(addr, ft_tolower);
	return (len);
}

size_t	f_print_hex(char c, unsigned int nbr)
{
	size_t			len;

	len = 0;
	if (c == 'x')
		len = f_convert_to_hex(nbr, ft_tolower);
	else if (c == 'X')
		len = f_convert_to_hex(nbr, ft_toupper);
	return (len);
}
