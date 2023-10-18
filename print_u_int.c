/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:27:43 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/18 09:28:17 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int	num_length(unsigned long num)
{
	if (num < 0)
		return (1 + num_length(-num));
	if (num < 10)
		return (1);
	return (1 + num_length(num / 10));
}

static int	itoout_loop(unsigned long num, int index)
{
	char	temp;
	int		written_chars;

	written_chars = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		written_chars++;
		num = -num;
	}
	if (num >= 10)
		written_chars = itoout_loop(num / 10, index - 1);
	temp = (num % 10) + '0';
	write(1, &temp, 1);
	return (written_chars + 1);
}

int	print_u_int(unsigned int int_num)
{
	unsigned long	long_num;
	int				length;

	long_num = (unsigned long)int_num;
	length = num_length(long_num);
	itoout_loop(long_num, length - 1);
	return (length);
}
