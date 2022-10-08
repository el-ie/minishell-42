/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:27:42 by eamar             #+#    #+#             */
/*   Updated: 2022/10/03 02:50:22 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strlen_pipex(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * @warning modified name beceause  conflict with libft
 * @brief 
 * 
 * @param s 
 * @return char* 
 */
char	*ft_strdup_pipex(const char *s)
{
	char		*dest;
	const int	size = ft_strlen_pipex(s);

	dest = malloc(sizeof(char) * (size + 1));
	if (dest == 0)
		return (0);
	while (*s)
		*dest++ = *s++;
	*dest = '\0';
	return (dest - size);
}

char	*ft_strjoin_pipex(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup_pipex(s2));
	if (!s2)
		return (0);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (free_and_return(s1, s2, str));
}

char	*free_and_return(char *s1, char *s2, char *str)
{
	free(s1);
	free(s2);
	return (str);
}

char	*ft_strjoin_pipex_nofree(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (0);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		save_status_free_exec_clean_exit(1);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}
