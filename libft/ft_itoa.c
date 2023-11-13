/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:19:42 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/06 07:58:55 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	f_digit_count(int n)
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

static char	*f_make_str(int n, char *num_a, size_t count, size_t i)
{
	int	sign;

	sign = 1;
	if (n == 0)
		num_a[i++] = '0';
	if (n < 0)
	{
		while (n <= -2147483647)
		{
			num_a[i++] = (n % 10) * -1 + '0';
			n /= 10;
		}
		sign = -1;
		n *= sign;
	}
	while (n > 0 && i <= count)
	{
		num_a[i++] = n % 10 + '0';
		n /= 10;
	}
	if (sign < 0)
		num_a[i++] = '-';
	num_a[i] = '\0';
	return (num_a);
}

char	*ft_itoa(int n)
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
