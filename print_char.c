/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:32:48 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/17 10:35:02 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this file primarily exists so everything is clean.
// its just for two lines

#include "printf.h"

#include <stdio.h>

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}
