/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:18:25 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:17:35 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_put_uint_fd(unsigned long int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd);
	}
	else
		ft_putchar_fd((nbr % 10) + '0', fd);
}
