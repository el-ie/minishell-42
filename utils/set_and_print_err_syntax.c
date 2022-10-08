/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_print_err_syntax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:23:27 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 12:23:54 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_and_print_err_syntax(void)
{
	int	len;

	len = ft_strlen("minishell: parse error near unexpected token `|'\n");
	get_data((t_data *)0)->status_last_cmd = 2;
	write(2, "minishell: parse error near unexpected token `|'\n", len);
}
