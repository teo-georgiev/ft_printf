/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:11:19 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/13 11:27:00 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

/* Helper function */

size_t	f_num_args(const char *str)
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

void	f_convert_to_hex(unsigned long nbr, int f(int))
{
	char	*base = "0123456789abcdef";
	
	if (nbr > 16)
	{
		f_convert_to_hex(nbr / 16, f);
		ft_putchar_fd(f(base[nbr % 16]), 1);
	}
	else if (nbr <= 16 && nbr >= 0)
		ft_putchar_fd(f(base[nbr % 16]), 1);
}

/* Conversion function */

void	f_print_int(va_list args)
{
	int	placeholder;

	placeholder = va_arg(args, int);
	ft_putnbr_fd(placeholder, 1);
}

void	f_print_char(va_list args)
{
	int	placeholder;

	placeholder = va_arg(args, int);
	ft_putchar_fd(placeholder, 1);
}

void	f_print_str(va_list args)
{
	char	*placeholder;

	placeholder = va_arg(args, char *);
	ft_putstr_fd(placeholder, 1);
}

void	f_print_address(unsigned long addr)
{
	if (addr > 0)
	{
		ft_putstr_fd("0x", 1);
		f_convert_to_hex(addr, ft_tolower);
	}
	else
		ft_putchar_fd('0', 1);
}

void	f_print_hex_lower(va_list args)
{
	unsigned int	placeholder;

	placeholder = va_arg(args, unsigned int);
	f_convert_to_hex((unsigned long)placeholder, ft_tolower);
}

void	f_print_hex_upper(va_list args)
{
	unsigned int	placeholder;

	placeholder = va_arg(args, unsigned int);
	f_convert_to_hex((unsigned long)placeholder, ft_toupper);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		num_args;
	int		i;

	va_start(args, str);
	num_args = f_num_args(str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar_fd('%', 1);
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			f_print_int(args);
		else if (str[i] == '%' && str[i + 1] == 'c')
			f_print_char(args);
		else if (str[i] == '%' && str[i + 1] == 's')
			f_print_str(args);
		else if (str[i] == '%' && str[i + 1] == 'p')
			f_print_address((unsigned long)&args);
		else if (str[i] == '%' && str[i + 1] == 'x')
			f_print_hex_lower(args);
		else if (str[i] == '%' && str[i + 1] == 'X')
			f_print_hex_upper(args);
		else if (str[i] != '%' && str[i - 1] != '%')
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	int	i = 10;
	int	num = 877767343;
	char *str = "Lorem ipsum dolor";

	ft_printf("Number:\t\t%d", i);
	ft_printf("%c", '\n');
	
	ft_printf("Character\t%c", 'T');
	ft_printf("%c", '\n');
	
	ft_printf("String:\t\t%s", str);
	ft_printf("%c", '\n');
	
	ft_printf("Address:\t%p", str);
	ft_printf("%c", '\n');

	ft_printf("\nHex test:\n");
	ft_printf("Hex lower:\t%x\n", num);
	ft_printf("Hex upper:\t%X\n", num);
	return (0);
}

	// Check the number of arguments based on how many % args there are 
	// in the const char

	// check the characters until end of str or until '%' encountered
	// if '%' encountered
		// function to compate what the next character is
		// if '%' print '%' character
		// (DONE) if 'c' call ft_putchar
		// (DONE) if 's' call ft_putstr
		// if 'p' >>> function to convert a pointer value into characters?
		// (DONE) if 'd' or 'i' call ft_putnbr
		// if 'u' >>> function to printf unsigned decimal
		// if 'x' >>> function to convert a num from base 10 to base 16 ->
			// convert to string lowercase -> ft_putstr
		// if 'X' >>> function to convert a num from base 10 to base 16 ->
			// convert to string lowercase -> ft_putstr