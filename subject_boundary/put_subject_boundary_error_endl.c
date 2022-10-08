/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_subject_boundary_error_endl.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:22:54 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 01:40:55 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	put_subject_boundary_error_endl(char *error)
{
	static char	*prefix = "Subject boundary error : minishell must not handle ";

	if (error == (char *)0)
		return (1);
	get_data((t_data *)0)->status_last_cmd = 2;
	write(2, prefix, ft_strlen(prefix));
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	return (1);
}
