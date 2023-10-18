/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:58:12 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/18 09:11:05 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hexa_rec(int num, char case_format)
{
	int		written_chars;

	written_chars = 0;
	if (num >= 16)
		written_chars += print_hexa_rec(num / 16, case_format);
	if (case_format == 'x')
		write(1, &"0123456789abcdef"[num % 16], 1);
	if (case_format == 'X')
		write(1, &"0123456789ABCDEF"[num % 16], 1);
	written_chars ++;
	return (written_chars);
}

int	print_hexa(int num, char case_format)
{
	int		written_chars;

	written_chars = 2;
	write(1, "0", 1);
	write(1, &case_format, 1);
	written_chars += print_hexa_rec(num, case_format);
	return (written_chars);
}
