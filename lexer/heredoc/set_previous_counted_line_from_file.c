/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_previous_counted_line_from_file.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 06:57:53 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 11:41:03 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_previous_counted_line_from_file(int nbr)
{
	static const char	*filename = ".tmp_counted_line";
	int					fd;

	fd = open(filename, O_RDWR | O_CREAT, 0755);
	if (fd < 0)
		return ;
	ft_putnbr_fd(nbr, fd);
	write(fd, "\n", 1);
	close(fd);
}
