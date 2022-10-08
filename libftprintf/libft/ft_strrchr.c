/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:00:52 by apayet            #+#    #+#             */
/*   Updated: 2021/12/01 15:43:24 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ps;

	ps = (char *) s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (ps[len] == (char)c)
			return (&ps[len]);
		len--;
	}
	return (NULL);
}
