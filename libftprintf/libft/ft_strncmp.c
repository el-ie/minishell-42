/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:56:33 by apayet            #+#    #+#             */
/*   Updated: 2021/11/29 11:50:45 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while ((ps1[i] == ps2[i]) && ps2[i] && ps1[i] && i < n)
	{
		i++;
	}
	if (i == n)
		return (0);
	if (ps1[i] != ps2[i])
		return (ps1[i] - ps2[i]);
	if (ps2[i] == 0 && ps1[i] != 0)
		return (ps2[i - 1] - ps1[i - 1]);
	return (ps1[i] - ps2[i]);
}
