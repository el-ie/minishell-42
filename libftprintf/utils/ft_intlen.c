/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:07:05 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:17:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

size_t	ft_intlen(long long int value, size_t base_len)
{
	int	count;

	count = 0;
	if (value <= 0)
	{
		count++;
		value = value * -1;
	}
	while (value > 0)
	{
		count++;
		value = value / base_len;
	}
	return (count);
}
