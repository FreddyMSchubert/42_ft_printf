/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:45:48 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/17 09:06:33 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	num_length(long num)
{
	if (num < 0)
		return (1 + num_length(-num));
	if (num < 10)
		return (1);
	return (1 + num_length(num / 10));
}

static void	itoout_loop(long num, int index)
{
	char	temp;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		itoout_loop(num / 10, index - 1);
	temp = (num % 10) + '0';
	write(1, &temp, 1);
}

void	print_int(int	int_num)
{
	long	long_num;
	int		length;

	long_num = (long)int_num;
	length = num_length(long_num);
	itoout_loop(long_num, length - 1);
}
