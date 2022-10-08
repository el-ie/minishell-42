/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_arc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:02:52 by apayet            #+#    #+#             */
/*   Updated: 2022/06/15 17:55:06 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_arc(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	if (!s1)
		return ((char *)0);
	i = 0;
	j = 0;
	len = (int) ft_strlen(s1) + (int) ft_strlen(s2) + 1;
	res = (char *)ft_malloc(sizeof(*res) * len);
	if (!res)
		return ((char *)0);
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
