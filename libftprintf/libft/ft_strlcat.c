/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:42:29 by apayet            #+#    #+#             */
/*   Updated: 2021/11/24 09:49:17 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_len;

	i = ft_strlen(dest);
	d_len = i;
	j = 0;
	if (src[0] == '\0')
		return (ft_strlen(dest));
	if (size <= d_len)
		return (size + ft_strlen(src));
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (d_len + ft_strlen(src));
}
