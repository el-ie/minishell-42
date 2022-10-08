/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:08:23 by apayet            #+#    #+#             */
/*   Updated: 2021/12/04 18:01:51 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	len = (int) ft_strlen(s1) + (int) ft_strlen(s2) + 1;
	res = malloc(sizeof(*res) * len);
	if (!res)
		return (NULL);
	i = ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
