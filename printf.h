/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:39:22 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/17 11:04:05 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H

# define PRINTFT_H

# include <unistd.h>
# include <stdarg.h>

// the man the myth the legend
int	ft_printf(char *str, ...);

// printing functions
int	print_char(char c);
int	print_str(char *str);
int	print_int(int	int_num);
int	print_ptr(void *ptr);

#endif