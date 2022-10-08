/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:52:57 by apayet            #+#    #+#             */
/*   Updated: 2021/11/30 17:33:03 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset_incrementator(size_t *i, size_t *j)
{
	*i = 0;
	*j = 0;
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	reset_incrementator(&i, &j);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[k + i] && (i + k) < len)
	{
		i = i + k;
		while (big[i] && i < len)
		{
			if (big[i] != little[j])
				j = 0;
			if (big[i] == little[j])
				j++;
			if (!little[j])
				return ((char *)&big[(i + 1) - j]);
			i++;
		}
		reset_incrementator(&i, &j);
		k++;
	}
	return (NULL);
}
