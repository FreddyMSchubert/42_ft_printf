/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:33:26 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/17 10:05:37 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_str(char *str)
{
	int		counter;
	char	temp_char;

	counter = 0;
	while (str[counter])
	{
		temp_char = (char)str[counter];
		write(1, &temp_char, 1);
		counter++;
	}
}
