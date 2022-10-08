/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:26:11 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:13:34 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_convert_x_format(t_payload *ref)
{
	unsigned long long int	number;
	char					res[20];
	size_t					len_p;

	number = (unsigned long long int)ref[0].value;
	len_p = ft_uintlen(number, ft_strlen("0123456789abcdef"));
	if (ref[0].spec == 'x')
		ft_itoa_base(number, &res[0], "0123456789abcdef", len_p);
	else
		ft_itoa_base(number, &res[0], "0123456789ABCDEF", len_p);
	res[len_p + 1] = '\0';
	ft_putstr_fd(&res[1], 1);
	ref[0].printed_char = len_p;
}
