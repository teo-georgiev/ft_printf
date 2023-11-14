/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:11:19 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/14 11:03:31 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"
#include <stdio.h>

void	separator(void)
{
	ft_printf("\n...........................\n");
}

int	main(void)
{
	char	*str;

	str = "Lorem ipsum dolor";
	ft_printf("%d\n", ft_printf("Number:\t\t%d\n", 10));
	printf("%d\n", printf("Number:\t\t%d\n", 10));
	separator();
	ft_printf("%d\n", ft_printf("Number:\t\t%d\n", 21474836));
	printf("%d\n", printf("Number:\t\t%d\n", 21474836));
	separator();
	ft_printf("%d\n", ft_printf("Character:\t%c\n", 'T'));
	printf("%d\n", printf("Character:\t%c\n", 'T'));
	separator();
	ft_printf("%d\n", ft_printf("String:\t\t%s\n", str));
	printf("%d\n", printf("String:\t\t%s\n", str));
	separator();
	ft_printf("%d\n", ft_printf("Addresses:\t%p\n", str));
	printf("%d\n", printf("Addresses:\t%p\n", str));
	separator();
	ft_printf("%d\n", ft_printf("Hex lower:\t%x\n", 123456789));
	printf("%d\n", printf("Hex lower:\t%x\n", 123456789));
	separator();
	ft_printf("%d\n", ft_printf("Hex upper:\t%X\n", 123456789));
	printf("%d\n", printf("Hex upper:\t%X\n", 123456789));
	separator();
	ft_printf("%d\n", ft_printf("Unsigned int:\t%u\n", -10));
	printf("%d\n", printf("Unsigned int:\t%u\n", -10));
	separator();
	return (0);
}
