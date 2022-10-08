/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:34:01 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:18:31 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_va_arg_handler(t_payload *ref)
{
	void	(*p_get[ENUM_MAX])(t_payload *);

	p_get[CHAR] = ft_get_char;
	p_get[STRING] = ft_get_string;
	p_get[POINTER] = ft_get_pointer;
	p_get[DIGIT] = ft_get_digit;
	p_get[IDIGIT] = ft_get_digit;
	p_get[UINT] = ft_get_uint;
	p_get[HEX] = ft_get_x;
	p_get[SHIFT_HEX] = ft_get_x;
	p_get[PRINT_POURCENT] = ft_get_ignore_spec;
	if (ft_check_spec_f("cspdiuxX%", ref) != -1)
	{
		p_get[ft_check_spec_f("cspdiuxX%", ref)](ref);
		ft_funct_handler(ref);
	}
}
