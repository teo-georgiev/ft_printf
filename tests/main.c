/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:11:19 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/15 17:41:53 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	separator(void)
{
	ft_printf("...........................\n");
}

void	test_d(char *str)
{
	ft_printf("%d\n", ft_printf("Number:\t\t%d\n", 10));
	printf("%d\n", printf("Number:\t\t%d\n", 10));
	separator();
	ft_printf("%d\n", ft_printf("Number:\t\t%d\n", INT_MAX));
	printf("%d\n", printf("Number:\t\t%d\n", INT_MAX));
	separator();
	ft_printf("%d\n", ft_printf("Number:\t\t%d\n", INT_MIN));
	printf("%d\n", printf("Number:\t\t%d\n", INT_MIN));
	separator();
	ft_printf("%d\n", ft_printf("Number:\t\t%d\n", 0));
	printf("%d\n", printf("Number:\t\t%d\n", 0));
	separator();
}

void	test_c(char *str)
{
	ft_printf("Character tests:\n");
	ft_printf(" %c %c %c ", '0', 0, '1');
	printf(" %c %c %c ", '0', 0, '1');
	//ft_printf("%d\n", ft_printf(" %c %c %c ", '0', 0, '1'));
	//printf("%d\n", printf(" %c %c %c ", '0', 0, '1'));
	separator();
	// ft_printf("%d\n", ft_printf("Hex lower:\t%x\n", 123456789));
	// printf("%d\n", printf("Hex lower:\t%x\n", 123456789));
	// separator();
	// ft_printf("%d\n", ft_printf("Hex upper:\t%X\n", 123456789));
	// printf("%d\n", printf("Hex upper:\t%X\n", 123456789));
	// separator();
	// ft_printf("%d\n", ft_printf("Unsigned int:\t%u\n", -10));
	// printf("%d\n", printf("Unsigned int:\t%u\n", -10));
	// separator();
}

void	test_s(char *str)
{
	ft_printf("String tests:\n");
	ft_printf("%d\n", ft_printf(" NULL %s NULL ", NULL));
	separator();
	ft_printf("%d\n", ft_printf(" %s", "can it handle \t and \n?"));
	printf("%d\n", printf(" %s", "can it handle \t and \n?"));
	return ;
}

void	test_p(char *str)
{
	ft_printf("Address tests:\n");
	ft_printf("%d\n", ft_printf("Address:\t%p\n", str));
	printf("%d\n", printf("Address:\t%p\n", str));
	separator();
	ft_printf("%d\n", ft_printf(" %p ", ""));
	printf("%d\n", printf(" %p ", ""));
	separator();
	return ;
}

void	test_x(char *str)
{
	return ;
}

void	test_u(char *str)
{
	return ;
}

void	test_percent(char *str)
{
	return ;
}

void	test_mix(char *str)
{
	return ;
}

void	test_no_format(char *str)
{
	ft_printf("%d\n", ft_printf("%s", str));
	printf("%d\n", printf("%s", str));
	return ;
}


int	main(void)
{
	char	*str;

	str = "Lorem ipsum dolor";
	test_c(str);
	//test_p(str);
	//test_no_format("\x01\x02\a\v\b\f\r");
	return (0);
}
