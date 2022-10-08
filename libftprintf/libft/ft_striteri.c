/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:18:53 by apayet            #+#    #+#             */
/*   Updated: 2021/12/04 17:59:41 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	len;
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, (char *) &s[i]);
		i++;
	}
	s[i] = '\0';
}
