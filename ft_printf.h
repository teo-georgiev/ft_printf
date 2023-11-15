/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgie <tgeorgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:11:49 by tgeorgie          #+#    #+#             */
/*   Updated: 2023/11/15 12:12:04 by tgeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
size_t	f_print_unsigned_int(va_list args);
size_t	f_print_address(unsigned long addr);
size_t	f_print_str(va_list args);
size_t	f_print_int(char c, va_list args);
size_t	f_print_hex(char c, va_list args);

#endif
