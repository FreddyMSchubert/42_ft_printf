/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:57:02 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/18 09:20:04 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int	print_addr(unsigned long address)
{
	int		written_chars;

	written_chars = 0;
	if (address >= 16)
		written_chars += print_addr(address / 16);
	write(1, &"0123456789abcdef"[address % 16], 1);
	written_chars ++;
	return (written_chars);
}

int	print_ptr(void *ptr)
{
	int		written_chars;

	written_chars = 2;
	write(1, "0x", 2);
	written_chars += print_addr((unsigned long) ptr);
	return (written_chars);
}
