/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:10:04 by apayet            #+#    #+#             */
/*   Updated: 2021/12/06 11:17:25 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_charset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* no space counted for '\0'
 * */
static int	count_char_trimed(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i] && char_is_charset(set, s1[i]))
	{
		count++;
		i++;
	}
	i = ft_strlen(s1) - 1;
	while (s1[i] && char_is_charset(set, s1[i]))
	{
		count++;
		i--;
	}
	if ((count / 2) == (int) ft_strlen(s1))
		return (0);
	return ((int) ft_strlen(s1) - count);
}

static char	*ft_new_string(int new_len, int *i, char *res, const char *s1)
{
	int	j;

	j = 0;
	while (j < new_len)
	{
		res[j] = s1[*i];
		j++;
		*i = *i + 1;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		new_len;
	int		i;
	char	*res;

	if (!s1)
		return (NULL);
	i = 0;
	res = NULL;
	new_len = count_char_trimed(s1, set);
	if (!new_len)
	{
		res = ft_strdup("");
		return (res);
	}
	res = malloc(sizeof(char) * (new_len + 1));
	if (!res)
		return (NULL);
	while (char_is_charset(set, s1[i]))
		i++;
	res = ft_new_string(new_len, &i, res, s1);
	return (res);
}
