/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:41:19 by apayet            #+#    #+#             */
/*   Updated: 2021/11/23 17:09:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_toupper(int c)
{
	if (!ft_isupper(c) && ft_isalpha(c))
		return (c - 32);
	return (c);
}
