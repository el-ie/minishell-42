/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:25:24 by apayet            #+#    #+#             */
/*   Updated: 2021/12/06 11:14:15 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*clean_s_zero(const char *s, char c)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(s);
	if (!tmp)
		return ((char *) 0);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == c)
			tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

static char	**do_split(char *seg_str, int s_len, char **splited, int *word)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!seg_str)
		return ((char **)0);
	while (++i, i < s_len)
	{
		if (seg_str[i] != '\0')
		{
			splited[j] = ft_strdup(&seg_str[i]);
			if (!splited[j])
			{
				*word = -1;
				return (splited);
			}
			while (seg_str[i] != '\0' && i < s_len)
				i++;
			j++;
			if (j == *word)
				splited[j] = (char *) 0;
		}
	}
	return (splited);
}

static int	count_word(const char *s, char c, int counter, int state)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	if (s[i] != c)
	{
		state = 1;
		i++;
	}
	while (s[i])
	{
		if (state && s[i] == c)
		{
			state = 0;
			counter++;
		}
		if (!state && s[i] != c)
			state = 1;
		i++;
	}
	if (s[i - 1] != c)
		counter++;
	return (counter);
}

static char	**free_splited(char **splited, const char *s, char c)
{
	int	i;
	int	max;

	i = 0;
	max = count_word(s, c, 0, 0);
	while (i < max)
	{
		if (splited[i])
			free(splited[i]);
		i++;
	}
	free(splited);
	splited = NULL;
	return (splited);
}

char	**ft_split(const char *s, char c)
{
	int		word;
	char	**splited;
	char	*seg_str;

	word = count_word(s, c, 0, 0);
	if (word == 0)
	{
		splited = malloc(sizeof(char *) * 1);
		if (!splited)
			return (NULL);
		splited[0] = 0;
		return (splited);
	}
	seg_str = clean_s_zero(s, c);
	if (!seg_str)
		return (NULL);
	splited = malloc(sizeof(char *) * (word + 1));
	if (!splited)
		return ((char **) 0);
	splited = do_split(seg_str, (int) ft_strlen(s), splited, &word);
	if (word == -1)
		splited = free_splited(splited, s, c);
	free(seg_str);
	return (splited);
}
