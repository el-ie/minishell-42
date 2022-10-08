/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_arc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:56:00 by apayet            #+#    #+#             */
/*   Updated: 2022/06/15 17:57:03 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 
 * 
 * @param data 
 * @param s1 
 * @return char* 
 */
char	*ft_strdup_arc(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen((char *)s1);
	res = (char *) ft_malloc(sizeof(*res) * (len + 1));
	if (!res)
		return ((char *)0);
	ft_memcpy(res, s1, len + 1);
	(void)s1;
	return (res);
}
