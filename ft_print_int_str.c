/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:34:27 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/15 18:06:27 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// static size_t	num_len(int num)
// {
// 	size_t	len;

// 	len = 0;
// 	if (num == 0)
// 		return (len = 1);
// 	if (num < 0)
// 		len = 1;
// 	while (num != 0)
// 	{
// 		num /= 10;
// 		len++;
// 	}
// 	return (len);
// }

size_t	f_print_int(char c, int nbr)
{
	size_t	len;
	
	len = 0;
	if (c == 'd' || c == 'i')
		len += ft_putnbr_fd(nbr, 1);
	else if (c == 'c')
		len += ft_putchar_fd(nbr, 1);
	return (len);
}

size_t	f_print_str(const char *str)
{
	size_t		len;

	len = 0;
	if (str == NULL)
	{
		len = write(1, "(null)", 6);
		return (len);
	}
	while (str[len])
		len += write(1, &str[len], 1);
	return (len);
}
