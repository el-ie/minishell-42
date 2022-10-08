/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:38:53 by apayet            #+#    #+#             */
/*   Updated: 2022/09/09 08:41:17 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*s_diff;

	if (s == (char *)0)
		return (0);
	s_diff = s;
	while (*s_diff)
		s_diff++;
	return (s_diff - s);
}
