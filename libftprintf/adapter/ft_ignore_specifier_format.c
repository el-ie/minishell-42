/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ignore_specifier_format.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:27:09 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:13:48 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/**
 * Value need to do not consume va_args
 * **/
void	ft_ignore_specifier_format(t_payload *ref)
{
	(void) ref;
	ft_putchar_fd('%', 1);
	ref[0].increase_i = 1;
	ref[0].printed_char = 1;
}
