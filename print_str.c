/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:33:26 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/18 09:17:34 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int		counter;
	char	temp_char;

	counter = 0;
	if (!str)
		return (print_str("(null)"), 6);
	while (str[counter])
	{
		temp_char = (char)str[counter];
		write(1, &temp_char, 1);
		counter++;
	}
	return (counter);
}
