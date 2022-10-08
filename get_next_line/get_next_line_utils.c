/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:58:28 by apayet            #+#    #+#             */
/*   Updated: 2022/10/03 15:16:00 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_free(void *bloc)
{
	free(bloc);
	bloc = (void *)0;
	return (bloc);
}

/**
 * @brief This function is a custom function
 * Its like strlen, except it stop also on '\n'
 */
int	ft_line_len(char *buff, int fstrlen)
{
	char	*p;

	if (!buff)
		return (0);
	p = (char *)buff;
	while (*p)
	{
		if ((char)*p == '\n' && fstrlen == 0)
			return (p - buff);
		p++;
	}
	return (p - buff);
}

/**
 * Return the number of char copied
 * Warning this function is custom
 * You need to set the '\0' after the call
 * */
size_t	custom_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *swap, char *buffer)
{
	char	*res;
	size_t	i;
	size_t	len;

	i = 0;
	if (!buffer)
		return ((char *)0);
	if (!swap)
	{
		swap = malloc(sizeof(char) * 1);
		if (!swap)
			return ((char *)0);
		swap[0] = '\0';
	}
	len = ft_line_len(swap, 1) + ft_line_len(buffer, 1);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return ((char *)0);
	i = custom_strcpy(&res[i], swap);
	i = i + custom_strcpy(&res[i], buffer);
	res[i] = '\0';
	swap = (char *)ft_free((void *)swap);
	return (res);
}

/*
 * This function create a new allocated string
 * @param :
 * 	buff : the adress of the buffer to duplicate
 * 	size : the max char to dup
 * @return :
 * 	the new allocated buffer.
 * */
char	*ft_strndup(char *buff, size_t size)
{
	size_t	i;
	size_t	len;
	char	*new_buff;

	i = 0;
	new_buff = (char *)0;
	if (!buff)
		len = 0;
	else
		len = ft_line_len(buff, 1);
	new_buff = malloc(sizeof(char) * (len + 1));
	if (!new_buff)
		return ((char *) 0);
	if (buff)
	{
		while (buff[i] && i < size)
		{
			new_buff[i] = buff[i];
			i++;
		}
	}
	new_buff[i] = '\0';
	return (new_buff);
}
