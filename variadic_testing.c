/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_testing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:02 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/14 10:22:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	variadic_testing(int count, ...)
{
    va_list args;
    va_start(args, count);

    int total = 0;
    for(int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

int main()
{
	printf("%d", variadic_testing(10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 123));
	return 1;
}