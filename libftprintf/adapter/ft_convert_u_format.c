/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:00:49 by apayet            #+#    #+#             */
/*   Updated: 2022/06/01 19:38:33 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_convert_u_format(t_payload *ref)
{
	ft_put_uint_fd(((u_int64_t *)ref[0].value)[0], 1);
	ref[0].printed_char = ft_uintlen(*(u_int64_t *)ref[0].value, 10);
}
