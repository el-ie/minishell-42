/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:58:26 by apayet            #+#    #+#             */
/*   Updated: 2022/06/01 19:39:16 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_itoa_base(u_int64_t value, char *res, char *base, size_t len_p)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	while (!(len_p <= 0))
	{
		res[len_p] = base[value % base_len];
		value = value / base_len;
		len_p--;
	}
}
