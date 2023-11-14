/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:32:28 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/14 10:59:47 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

static size_t	f_digit_count(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (count = 1);
	if (n < 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	f_str_reverse(char *num_a, size_t i)
{
	char	tmp;
	size_t	start;
	size_t	end;

	start = 0;
	end = i - 1;
	while (start < end)
	{
		tmp = num_a[start];
		num_a[start] = num_a[end];
		num_a[end] = tmp;
		start++;
		end--;
	}
}

static char	*f_make_str(unsigned int n, char *num_a, size_t count, size_t i)
{
	if (n == 0)
		num_a[i++] = '0';
	while (n > 0 && i <= count)
	{
		num_a[i++] = n % 10 + '0';
		n /= 10;
	}
	num_a[i] = '\0';
	return (num_a);
}

char	*f_uitoa(unsigned int n)
{
	char	*num_a;
	size_t	count;

	count = f_digit_count(n);
	num_a = malloc((count + 1) * sizeof(char));
	if (!num_a)
		return (0);
	num_a = f_make_str(n, num_a, count, 0);
	f_str_reverse(num_a, ft_strlen(num_a));
	return (num_a);
}

size_t	f_print_unsigned_int(va_list args)
{
	size_t			len;
	unsigned int	placeholder;
	char			*str;

	placeholder = va_arg(args, unsigned int);
	str = f_uitoa(placeholder);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	return (len);
}
