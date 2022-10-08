/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_di_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 08:15:11 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:12:45 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_convert_di_format(t_payload *ref)
{
	ref[0].printed_char += (size_t)ft_intlen(*((int *)ref[0].value), 10);
	ft_putnbr_fd(((int *)ref[0].value)[0], 1);
}
