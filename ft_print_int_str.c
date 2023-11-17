/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:34:27 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/17 08:38:47 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	f_print_int(char c, int nbr)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(nbr, 1));
	return (ft_putchar_fd(nbr, 1));
}

int	f_print_str(const char *str)
{
	if (str == NULL)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd((char *)str, 1));
}
