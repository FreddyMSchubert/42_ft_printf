/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:39:22 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/17 09:33:40 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H

# define PRINTFT_H

# include <unistd.h>
# include <stdarg.h>

void	print_char(char c);
void	print_str(char *str);
void	print_int(int	int_num);

#endif