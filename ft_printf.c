/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:40:32 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/17 10:02:16 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>

#include "printf.h"

int		identify_specials(char *str, va_list args, int counter)
{
	if (str[counter + 1] == 'd')
		print_int(va_arg(args, int));
	if (str[counter + 1] == 'c')
		print_char((char) va_arg(args, int));
	if (str[counter + 1] == 's')
		print_str(va_arg(args, char *));
	return (counter + 1);
}

int		ft_printf(char *str, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, str);
	if (!str)
		return (va_end(args), 0);
	while (str[counter] != '\0')
	{
		if (str[counter] == '%')
			counter = identify_specials(str, args, counter);
		else
			write(1, &str[counter], 1);
		counter++;
	}
	va_end(args);
	return (counter);
}

// Assume ft_printf is defined above or in another file
// and the necessary headers are included

int main(void)
{
    // Step 1: Just a string
    ft_printf("Hello, World!\n");

    // Step 2: Adding a char
    ft_printf("Char: %cBC\n", 'A');

    // Step 3: Introducing an int
    ft_printf("Int: %d\n", 42);

    // Step 4: String within a string
    ft_printf("String: %s\n", "OpenAI rocks!");

    // Step 5: Mix it up!
    ft_printf("Mix: %c %d %s\n", 'B', 7, "heaven");

    // Keep adding more complex cases as needed

    return 0;
}
