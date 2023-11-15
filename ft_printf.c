/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:11:19 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/15 12:58:03 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static size_t	f_num_args(const char *str)
{
	size_t		num;
	size_t		i;
	char const	*set;

	num = 0;
	i = 0;
	set = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr(set, str[i + 1]))
			num++;
		i++;
	}
	return (num);
}

int	f_print_options(va_list args, const char *str, int len, int i)
{
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			if (str[i + 1] == 'd' || str[i + 1] == 'i' \
				|| str[i + 1] == 'c' || str[i + 1] == '%')
				len += f_print_int(str[i + 1], args);
			if (str[i + 1] == 's')
				len += f_print_str(args);
			if (str[i + 1] == 'p')
				len += f_print_address((unsigned long)&args);
			if (str[i + 1] == 'x' || str[i + 1] == 'X')
				len += f_print_hex(str[i + 1], args);
			if (str[i + 1] == 'u')
				len += f_print_unsigned_int(args);
		}
		else if ((str[i] != '%' && str[i - 1] != '%') \
			|| (str[i] == '%' && str[i + 1] == '%'))
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		num_args;
	int		len;

	va_start(args, str);
	num_args = f_num_args(str);
	len = f_print_options(args, str, 0, -1);
	va_end(args);
	return (len);
}
