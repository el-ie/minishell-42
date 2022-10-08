/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:25:00 by apayet            #+#    #+#             */
/*   Updated: 2021/12/28 17:52:24 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*p_src;
	unsigned char	*p_dst;

	i = 0;
	if (!dest && !src)
		return (NULL);
	p_src = (unsigned char *) src;
	p_dst = (unsigned char *) dest;
	while (i < n)
	{
		ft_memset(&p_dst[i], p_src[i], 1);
		i++;
	}
	return (dest);
}
