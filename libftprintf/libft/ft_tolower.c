/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:45:53 by apayet            #+#    #+#             */
/*   Updated: 2021/11/23 17:04:10 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_tolower(int c)
{
	if (!ft_islower(c) && ft_isalpha(c))
		return (c + 32);
	return (c);
}
