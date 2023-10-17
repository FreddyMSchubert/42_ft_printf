/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:32:48 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/17 09:43:51 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this file primarily exists so everything is clean.
// its just for two lines

#include "printf.h"

#include <stdio.h>

void	print_char(char c)
{
	// printf("helllllllllll[%c]", c);
	write(1, &c, 1);
}
