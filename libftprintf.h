/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:12:18 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/14 11:01:32 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H 
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
size_t	f_print_unsigned_int(va_list args);
size_t	f_print_address(unsigned long addr);
size_t	f_print_str(va_list args);
size_t	f_print_int(char c, va_list args);
size_t	f_print_hex(char c, va_list args);

#endif
