/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:18:04 by apayet            #+#    #+#             */
/*   Updated: 2021/12/28 17:52:42 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen((char *)s1);
	res = (char *) malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, len + 1);
	return (res);
}
