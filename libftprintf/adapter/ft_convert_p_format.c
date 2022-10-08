/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:24:30 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:13:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_convert_p_format(t_payload *ref)
{
	unsigned long long int	number;
	char					res[20];
	size_t					len_p;

	number = (unsigned long long int)ref[0].value;
	len_p = ft_uintlen(number, ft_strlen("0123456789abcdef"));
	ft_itoa_base(number, &res[1], "0123456789abcdef", len_p);
	res[0] = '0';
	res[1] = 'x';
	res[len_p + 2] = '\0';
	ft_putstr_fd(res, 1);
	ref[0].printed_char = ft_strlen(res);
}
