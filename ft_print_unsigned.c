/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:32:28 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/15 12:20:21 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static size_t	f_uitoa(unsigned int nbr)
{
	size_t	len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (nbr > 10)
		len += f_uitoa(nbr / 10);
	len += write(1, &base[nbr % 10], 1);
	return (len);
}

size_t	f_print_unsigned_int(va_list args)
{
	size_t			len;
	unsigned int	placeholder;

	placeholder = va_arg(args, unsigned int);
	len = f_uitoa(placeholder);
	return (len);
}
