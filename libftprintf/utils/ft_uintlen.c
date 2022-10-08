/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:10:08 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:17:46 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

size_t	ft_uintlen(unsigned long long int value, size_t base_len)
{
	int	count;

	count = 0;
	if (value == 0)
		count++;
	while (value > 0)
	{
		count++;
		value = value / base_len;
	}
	return (count);
}
