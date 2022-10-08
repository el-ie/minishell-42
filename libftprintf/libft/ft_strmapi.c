/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:12:48 by apayet            #+#    #+#             */
/*   Updated: 2021/12/06 11:16:20 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = (int) ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = f(i, (char) s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
