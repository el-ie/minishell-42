/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:24:18 by apayet            #+#    #+#             */
/*   Updated: 2021/12/04 18:05:56 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_digit(long int nbr, int *sign)
{
	int				counter;

	counter = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		counter++;
		*sign = *sign * -1;
	}
	while (nbr > 0)
	{
		counter++;
		nbr = nbr / 10;
	}
	return (counter);
}

static char	*zero_nb_output(void)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int c)
{
	char		*ascii;
	int			len;
	long int	nbr;
	int			sign;

	sign = 1;
	nbr = (long int)c;
	if (nbr == 0)
		return (zero_nb_output());
	len = ft_count_digit(nbr, &sign);
	ascii = malloc(sizeof(char) * len + 1);
	if (!ascii)
		return (NULL);
	ascii[len] = '\0';
	while (nbr)
	{
		len--;
		ascii[len] = ((nbr * sign) % 10) + '0';
		nbr = nbr / 10;
	}
	if (sign == -1)
		ascii[--len] = '-';
	return (ascii);
}
