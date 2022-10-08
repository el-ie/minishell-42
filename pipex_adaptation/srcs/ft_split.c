/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:21:54 by eamar             #+#    #+#             */
/*   Updated: 2022/10/04 00:42:59 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	**ft_free_all(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	save_status_free_exec_clean_exit(1);
	return (0);
}

static int	ft_count_rows(char const	*s, char c)
{
	int	rows;
	int	i;

	rows = 0;
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && !(*s++ == c))
			i++;
		if (i)
			rows++;
		i = 0;
	}
	return (rows);
}

static int	ft_calcul_size(char const **s, char c)
{
	int		q;

	while (**s && **s == c)
		(*s)++;
	q = 0;
	while (s[0][q] && s[0][q] != c)
		q++;
	return (q);
}

char	**ft_split(char const *s, char c)
{
	char		**dest;
	int			rows;
	int			i;
	int			q;

	i = -1;
	if (!s)
		return (0);
	rows = ft_count_rows(s, c);
	dest = malloc(sizeof(char *) * (rows + 1));
	if (!dest)
		save_status_free_exec_clean_exit(1);
	while (++i < rows)
	{
		q = ft_calcul_size(&s, c);
		dest[i] = malloc(sizeof(char) * (q + 1));
		if (!dest[i])
			return (ft_free_all(dest));
		while (*s && *s != c)
			*dest[i]++ = *s++;
		*dest[i] = '\0';
		dest[i] -= q;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split_slash(char const *s, char c, int q)
{
	char		**dest;
	int			rows;
	int			i;

	i = -1;
	if (!s)
		return (0);
	rows = ft_count_rows(s, c);
	dest = malloc(sizeof(char *) * (rows + 1));
	if (!dest)
		save_status_free_exec_clean_exit(1);
	while (++i < rows)
	{
		q = ft_calcul_size(&s, c);
		dest[i] = malloc(sizeof(char) * (q + 2));
		if (!dest[i])
			return (ft_free_all(dest));
		while (*s && *s != c)
			*dest[i]++ = *s++;
		*dest[i] = '/';
		*(dest[i] + 1) = '\0';
		dest[i] -= q;
	}
	dest[i] = 0;
	return (dest);
}
