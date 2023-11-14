/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:34:27 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/14 10:58:33 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

static size_t	num_len(int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (len = 1);
	if (num < 0)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

size_t	f_print_int(char c, va_list args)
{
	size_t	len;
	int		placeholder;

	len = 0;
	placeholder = va_arg(args, int);
	if (c == 'd' || c == 'i')
	{
		len = num_len(placeholder);
		ft_putnbr_fd(placeholder, 1);
	}
	else if (c == 'c')
	{
		len = 1;
		ft_putchar_fd(placeholder, 1);
	}
	return (len);
}

size_t	f_print_str(va_list args)
{
	size_t	len;
	char	*placeholder;

	placeholder = va_arg(args, char *);
	len = ft_strlen(placeholder);
	ft_putstr_fd(placeholder, 1);
	return (len);
}
