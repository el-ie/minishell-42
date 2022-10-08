/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:00:17 by apayet            #+#    #+#             */
/*   Updated: 2021/11/26 12:01:49 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ps;

	i = 0;
	ps = (unsigned char *) s;
	while (i < n)
	{
		if (ps[i] == (unsigned char) c)
			return (&ps[i]);
		i++;
	}
	return (0);
}
