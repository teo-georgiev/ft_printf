/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:11:19 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/17 08:48:38 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	f_print_format(char format, va_list args)
{
	if (ft_strchr("cspdiuxX%", format))
	{
		if (format == 'd' || format == 'i' \
			|| format == 'c')
			return (f_print_int(format, va_arg(args, int)));
		else if (format == 's')
			return (f_print_str(va_arg(args, const char *)));
		else if (format == 'p')
			return (f_print_address(va_arg(args, unsigned long)));
		else if (format == 'x')
			return (f_print_hex(va_arg(args, unsigned int), ft_tolower));
		else if (format == 'X')
			return (f_print_hex(va_arg(args, unsigned int), ft_toupper));
		else if (format == 'u')
			return (f_print_unsigned_int(va_arg(args, unsigned int)));
		else if (format == '%')
			return (ft_putchar_fd('%', 1));
	}
	else
		return (ft_putchar_fd(format, 1));
	return (-1);
}

static int	f_print_control(va_list args, const char *str)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	len = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			flag = f_print_format(str[i + 1], args);
			i += 2;
		}
		else if (str[i] != '%')
			flag = ft_putchar_fd(str[i++], 1);
		else if (str[i] == '%' && !str[i + 1])
			break ;
		if (flag == -1)
			return (-1);
		len += flag;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = f_print_control(args, str);
	va_end(args);
	return (len);
}
