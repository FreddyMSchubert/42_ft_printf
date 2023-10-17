/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:40:32 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/17 11:04:54 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>

#include "printf.h"

int		identify_specials(char *str, va_list args, int counter)
{
	if (str[counter + 1] == 'd')
		return (print_int(va_arg(args, int)));
	if (str[counter + 1] == 'c')
		return (print_char((char) va_arg(args, int)));
	if (str[counter + 1] == 's')
		return (print_str(va_arg(args, char *)));
	if (str[counter + 1] == '%')
		return (print_char('%'));
	if (str[counter + 1] == 'p')
		return (print_ptr(va_arg(args, void *)));
	return (0);
}

int		ft_printf(char *str, ...)
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
	return (printed_chars_counter - 1);
}

// Assume ft_printf is defined above or in another file
// and the necessary headers are included

int main(void)
{
    // Existing test cases
    ft_printf("Hello, World!\n");
    ft_printf("Char: %cBC\n", 'A');
    ft_printf("Int: %d\n", 42);
    ft_printf("String: %s\n", "OpenAI rocks!");
    ft_printf("Mix: %c %d %s\n", 'B', 7, "heaven");
    ft_printf("%%percent baby\n");

    // New test cases
    // %p - Printing pointer in hexadecimal
    int var = 42;
	printf("pointer: %p/n", (void *)&var);
    ft_printf("Pointer: %p\n", (void *)&var);
    
    // %i - Printing integer (just like %d)
    ft_printf("Integer: %i\n", -42);
    
    // %u - Printing unsigned integer
    ft_printf("Unsigned: %u\n", 4200);
    
    // %x - Printing hexadecimal lowercase
    ft_printf("Hex lowercase: %x\n", 255);
    
    // %X - Printing hexadecimal uppercase
    ft_printf("Hex uppercase: %X\n", 255);

    return 0;
}