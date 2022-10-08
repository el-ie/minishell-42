/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funct_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:51:28 by apayet            #+#    #+#             */
/*   Updated: 2022/06/01 19:39:48 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_funct_handler(t_payload *ref)
{
	void	(*pf[ENUM_MAX])(t_payload *);

	pf[CHAR] = ft_convert_c_format;
	pf[STRING] = ft_convert_s_format;
	pf[POINTER] = ft_convert_p_format;
	pf[DIGIT] = ft_convert_di_format;
	pf[IDIGIT] = ft_convert_di_format;
	pf[UINT] = ft_convert_u_format;
	pf[HEX] = ft_convert_x_format;
	pf[SHIFT_HEX] = ft_convert_x_format;
	pf[PRINT_POURCENT] = ft_convert_c_format;
	if (ft_check_spec_f("cspdiuxX%", ref) != -1)
	{
		pf[ft_check_spec_f("cspdiuxX%", ref)](ref);
	}
}
