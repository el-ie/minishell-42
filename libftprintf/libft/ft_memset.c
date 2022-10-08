/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:54:42 by apayet            #+#    #+#             */
/*   Updated: 2021/11/23 15:37:41 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*pb;

	i = 0;
	pb = (unsigned char *) b;
	while (i < len)
	{
		pb[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
