/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:55:28 by healeksa          #+#    #+#             */
/*   Updated: 2024/04/04 18:14:12 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_uputnbr(unsigned long n);
int	ft_print_hex(unsigned long long n, char format);
int	ft_print_ptr(unsigned long long ptr);

#endif
