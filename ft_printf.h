/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:11:49 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/17 08:36:54 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	f_print_unsigned_int(unsigned int nbr);
int	f_print_address(unsigned long addr);
int	f_print_str(const char *str);
int	f_print_int(char c, int nbr);
int	f_print_hex(unsigned long nbr, int f(int));

#endif
