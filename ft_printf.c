/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:11:19 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/16 14:59:51 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <stdio.h>

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

static int	f_format(char format, va_list args)
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
	return (1);
}

static int	f_print_options(va_list args, const char *str, int len, int i)
{
	int	flag;

	flag = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			flag = f_format(str[i + 1], args);
			if (flag == -1)
				return (-1);
			len += flag;
			i += 2;
		}
		else if (str[i] == '%' && !str[i + 1])
			return (len);
		else if (str[i] != '%')
		{
			if (ft_putchar_fd(str[i], 1) == -1)
				return (-1);
			len++;
			i++;
		}
	}
	return (len);
}

static int	f_noformat(const char *str)
{
	int	len;
	int	i;
	int	flag;

	len = 0;
	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (str[i] != '%')
		{
			flag = ft_putchar_fd(str[i], 1);
			if (flag == -1)
				return (-1);
			len += flag;
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
	if (!num_args)
		return (f_noformat(str));
	len = f_print_options(args, str, 0, 0);
	va_end(args);
	return (len);
}
