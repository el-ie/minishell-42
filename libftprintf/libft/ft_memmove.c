/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:47:21 by apayet            #+#    #+#             */
/*   Updated: 2021/12/06 11:12:27 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_overlap(void *dest, const void *src)
{
	return (src < dest);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdst;

	i = 0;
	psrc = (unsigned char *) src;
	pdst = (unsigned char *) dest;
	if (!len || dest == src)
		return (dest);
	while (!ft_is_overlap(dest, src) && i < len)
	{
		pdst[i] = psrc[i];
		i++;
	}
	while (ft_is_overlap(dest, src) && len > 0)
	{
		pdst[len - 1] = psrc[len - 1];
		len--;
	}
	return (dest);
}
