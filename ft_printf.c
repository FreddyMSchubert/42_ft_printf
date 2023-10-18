/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:40:32 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/18 09:34:58 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>

#include "ft_printf.h"

static int	identify_specials(const char *str, va_list args, int counter)
{
	if (str[counter + 1] == 'd' || str[counter + 1] == 'i')
		return (print_int(va_arg(args, int)));
	if (str[counter + 1] == 'c')
		return (print_char((char) va_arg(args, int)));
	if (str[counter + 1] == 'u')
		return (print_u_int(va_arg(args, int)));
	if (str[counter + 1] == 's')
		return (print_str(va_arg(args, char *)));
	if (str[counter + 1] == '%')
		return (print_char('%'));
	if (str[counter + 1] == 'p')
		return (print_ptr(va_arg(args, void *)));
	if (str[counter + 1] == 'x')
		return (print_hexa(va_arg(args, int), 'x'));
	if (str[counter + 1] == 'X')
		return (print_hexa(va_arg(args, int), 'X'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		printed_chars_counter;

	counter = 0;
	printed_chars_counter = 0;
	va_start(args, str);
	if (!str)
		return (va_end(args), 0);
	while (str[counter] != '\0')
	{
		if (str[counter] == '%')
		{
			printed_chars_counter += identify_specials(str, args, counter);
			counter++;
		}
		else
		{
			write(1, &str[counter], 1);
			printed_chars_counter++;
		}
		counter++;
	}
	va_end(args);
	return (printed_chars_counter);
}
