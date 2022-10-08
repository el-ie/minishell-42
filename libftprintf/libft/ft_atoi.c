/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:49:47 by apayet            #+#    #+#             */
/*   Updated: 2021/12/01 15:53:40 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static int	ft_isop(int c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(const char *nptr)
{
	long int	nbr;
	int			sign;
	int			i;

	sign = 1;
	nbr = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_isop(nptr[i]))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
	}
	return ((int)nbr * sign);
}
