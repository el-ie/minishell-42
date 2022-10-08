/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:53:50 by apayet            #+#    #+#             */
/*   Updated: 2021/12/01 15:38:11 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ps;

	i = 0;
	ps = (char *) s;
	while (ps[i])
	{
		if (ps[i] == (char)c)
			return (&ps[i]);
		i++;
	}
	if (ps[i] == (char)c)
		return (&ps[i]);
	return ((char *) 0);
}
