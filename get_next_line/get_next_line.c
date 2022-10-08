/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 06:57:13 by apayet            #+#    #+#             */
/*   Updated: 2022/08/16 12:56:58 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_swap(char **swap, char *buffer)
{
	char	*membloc_new;

	membloc_new = (char *)0;
	if (!*swap)
	{
		*swap = ft_strndup(buffer, ft_line_len(buffer, 1));
		return ;
	}
	else
	{
		membloc_new = ft_strjoin_gnl(*swap, buffer);
		if (!membloc_new)
		{
			*swap = (char *)ft_free((void *)*swap);
			return ;
		}
		*swap = ft_strndup(membloc_new, ft_line_len(membloc_new, 1));
		membloc_new = (char *)ft_free((void *) membloc_new);
	}
}

void	swap_add(char **swap, int *last_line, t_gnl *m, char *buffer)
{
	int	char_p;

	if (*last_line == 1)
	{
		m[0].res = (char *)ft_free((void *)m[0].res);
		m[0].res = ft_strndup(*swap, ft_line_len(*swap, 1));
		*swap = (char *)ft_free((void *)*swap);
		m[0].do_ret = 1;
		return ;
	}
	char_p = read(m[0].fd, buffer, BUFFER_SIZE);
	buffer[char_p] = '\0';
	if (char_p == 0)
	{
		*last_line = 1;
		m[0].do_ret = 1;
		check_nl(swap, last_line, &m[0]);
	}
	else if (char_p != 0)
	{
		update_swap(swap, buffer);
		*last_line = 0;
		check_nl(swap, last_line, &m[0]);
	}
}

void	update_res(char **swap, int line_len, t_gnl *m)
{
	char	*membloc_left;
	int		len;

	len = 0;
	m[0].res = ft_strndup(*swap, line_len + 1);
	len = ft_line_len(&swap[0][line_len + 1], 1);
	membloc_left = ft_strndup(&swap[0][line_len + 1], len);
	*swap = (char *)ft_free((void *)*swap);
	*swap = ft_strndup(membloc_left, ft_line_len(membloc_left, 1));
	membloc_left = (char *)ft_free((void *)membloc_left);
	m[0].do_ret = 1;
}

void	check_nl(char **swap, int *last_line, t_gnl *m)
{
	int			char_p;
	static char	buffer[BUFFER_SIZE + 1] = {(char) 0};

	char_p = 0;
	if (!*swap && *last_line != 1)
	{
		char_p = read(m[0].fd, buffer, BUFFER_SIZE);
		if (char_p != 0)
			update_swap(swap, &buffer[0]);
		else
			*last_line = 1;
		return ;
	}
	if (m[0].res)
		m[0].res = (char *)ft_free((void *) m[0].res);
	if (ft_line_len(*swap, 0) == (int) ft_line_len(*swap, 1))
		swap_add(swap, last_line, &m[0], &buffer[0]);
	else
		update_res(swap, ft_line_len(*swap, 0), &m[0]);
}

char	*get_next_line(int fd, int need_reset)
{
	t_gnl		m;
	static char	*swap = NULL;
	static int	last_line = 0;

	swap = get_next_line_need_free(&swap, &last_line, need_reset);
	ft_memset(&m, 0, sizeof(t_gnl));
	m.fd = fd;
	if (m.fd == -1)
		return ((char *)0);
	if (read(fd, (char *)0, 0) == -1)
		return ((char *)0);
	while (m.do_ret != 1 && last_line != 1)
	{
		check_nl(&swap, &last_line, &m);
		if (m.do_ret && last_line)
		{
			swap = (char *)ft_free((void *)swap);
			if (m.res[0] == '\0')
				m.res = (char *)ft_free((void *)m.res);
			return (m.res);
		}
		if (m.do_ret)
			return (m.res);
	}
	return (swap = (char *)ft_free((void *)swap));
}
