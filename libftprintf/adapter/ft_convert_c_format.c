/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:45:37 by apayet            #+#    #+#             */
/*   Updated: 2022/06/01 19:44:16 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_convert_c_format(t_payload *ref)
{
	unsigned char	*p_value;

	p_value = (unsigned char *)ref->value;
	ft_putchar_fd(p_value[0], 1);
	ref->printed_char = 1;
}
