/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:24:19 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/14 15:03:56 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>  // for write
#include <stdlib.h>  // for abs

int count_digits(int number) {
    int digit_count = 0;

    // Handle 0 as a special case
    if (number == 0) {
        return 1;
    }

    // Make sure the number is positive for counting
    number = abs(number);

    while (number > 0) {
        number /= 10;  // Shrink the number by one digit
        digit_count++;  // Increment the count
    }

    return digit_count;
}

void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* itoa(int num, char* str, int base) {
    int i = 0;
    int isNegative = 0;

    // Handle 0 explicitly, otherwise empty string is printed
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // Handle negative numbers only if base is 10
    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // Append negative sign for negative numbers
    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';  // Null-terminate string

    // Reverse the string
    reverse(str, i);

    return str;
}

int	how_many_percentage(char *message)
{
	int total = 0;
	for (int i = 0; message[i] != '\0'; i++)
	{
		if (message[i] == 'X')
			total++;
	}
	return (total);
}

void	printft(char *message, ...)
{
	va_list args;
	va_start(args, message);  // Corrected here
	for (int i = 0; message[i] != '\0'; i++)
	{
		if (message[i] == 'X')
		{
			int yay = va_arg(args, int);
			int yaydigits = count_digits(yay);
			char yaychar[20];  // Declared a char array
			itoa(yay, yaychar, 10);  // Fixed here
			write(1, yaychar, yaydigits);
		}
		else
			write(1, &message[i], 1);  // Fixed here
	}
	va_end(args);  // Don't forget to clean up!
}

int	main()
{
	printft("this is a text");
	write(1, "\n", 1);  // Just for readability
	printft("this is a text with the int X", 3);
	return 0;
}