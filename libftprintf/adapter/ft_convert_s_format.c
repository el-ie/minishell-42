/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:27:22 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:13:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_convert_s_format(t_payload *ref)
{
	char	*p_value;

	p_value = &*((char *)ref[0].value);
	ref[0].printed_char = ft_strlen(p_value);
	ft_putstr_fd(p_value, 1);
}
