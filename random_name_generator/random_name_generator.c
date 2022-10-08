/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_name_generator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:32:43 by apayet            #+#    #+#             */
/*   Updated: 2022/09/09 07:11:58 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	get_char_alphanum_from_random(int fd)
{
	int		readed;
	char	c_buff;

	readed = -1;
	readed = read(fd, &c_buff, 1);
	if (readed != -1)
	{
		while (ft_isalnum(c_buff) == 0)
		{
			readed = read(fd, &c_buff, 1);
			if (readed == -1)
			{
				return ('E');
			}
		}
		return (c_buff);
	}
	else
		return ('E');
}

static int	ft_is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	i = 2;
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_cpy_char_random_underscore(char *buffer, int *i, int fd, int len)
{
	while (*i < len)
	{
		if (ft_is_prime(*i) && *i > 6)
			buffer[*i] = '_';
		else
			buffer[*i] = get_char_alphanum_from_random(fd);
		*i += 1;
	}
	buffer[*i] = '\0';
}

static int	get_length_protected(int length_asked)
{
	if (length_asked > 127)
		return (126);
	else
		return (length_asked);
}

/**
 * @brief This function is designed to create a random string
 * 
 * @param prefix_str 
 * @param total_length 
 */
char	*random_name_generator(unsigned int len_filename, int is_hidded)
{
	int		fd;
	int		length;
	char	buffer[128];
	int		i;
	char	*result;

	length = 0;
	i = 1;
	if (len_filename == 0)
		return ((char *)0);
	length = get_length_protected(len_filename);
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return ((char *)0);
	if (is_hidded)
		buffer[0] = '.';
	else
		i = 0;
	ft_cpy_char_random_underscore(buffer, &i, fd, length);
	close(fd);
	result = ft_strdup(buffer);
	return (result);
}
