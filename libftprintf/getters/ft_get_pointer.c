/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:55:27 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:14:58 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_get_pointer(t_payload *ref)
{
	ref[0].p = va_arg(*(ref[0].list), unsigned long long int);
	ref[0].value = (void *)ref[0].p;
}
