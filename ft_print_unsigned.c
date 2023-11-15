/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:32:28 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/15 17:44:09 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

size_t	f_print_unsigned_int(unsigned int nbr)
{
	size_t	len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (nbr / 10 != 0)
		len += f_print_unsigned_int(nbr / 10);
	len += write(1, &base[nbr % 10], 1);
	return (len);
}
