/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:17:37 by apayet            #+#    #+#             */
/*   Updated: 2021/12/06 11:18:05 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*freeable(void)
{
	char	*res;

	res = malloc(sizeof(char) * 1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	start_init;
	size_t	len_str;
	char	*res;

	if (!s)
		return (NULL);
	res = NULL;
	start_init = start;
	if (ft_strlen(s) < (size_t) start)
		return (freeable());
	len_str = ft_strlen(&s[start]);
	if (len_str > len)
		len_str = len;
	if (len_str == 0)
		return (freeable());
	res = malloc(sizeof(*res) * (len_str + 1));
	if (!res)
		return (NULL);
	while (start - start_init < len && s[start])
	{
		res[start - start_init] = s[start];
		start++;
	}
	res[start - start_init] = '\0';
	return (res);
}
