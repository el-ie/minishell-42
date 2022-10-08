/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_previous_counted_line_from_file.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 06:58:44 by apayet            #+#    #+#             */
/*   Updated: 2022/10/06 00:30:38 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
*/
int	get_previous_counted_line_from_file(void)
{
	static const char	*filename = ".tmp_counted_line";
	int					fd;
	char				*result_string;
	int					result_nbr;
	int					counted_line_minishell;

	result_string = (char *)0;
	result_nbr = 0;
	counted_line_minishell = get_data((t_data *)0)->count_line_for_heredoc_warn;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (result_nbr + counted_line_minishell);
	result_string = get_next_line(fd, FALSE);
	if (result_string == (char *)0)
	{
		close(fd);
		return (result_nbr + counted_line_minishell);
	}
	result_nbr = ft_atoi(result_string);
	free(result_string);
	result_string = (char *)0;
	get_next_line(fd, TRUE);
	close(fd);
	return (result_nbr + counted_line_minishell);
}
